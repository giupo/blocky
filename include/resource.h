#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include <map>
#include <string>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "screen.h"
#include "service_locator.h"



/**
 * @brief Allocates and deallocates Resources.
 *
 * References data based on names
 */
class ResourceManager {
public:
  ResourceManager() : v_res() {}
  ~ResourceManager() {
    v_res.clear();
  }

  std::shared_ptr<SDL_Surface> getImage(const std::string name) {
    auto search = v_res.find(name);
    if(search == v_res.end()) {
      v_res[name] = std::shared_ptr<SDL_Surface>(ResourceManager::loadImage(name));
    }
    return v_res[name];
  }
 
  static SDL_Surface* loadImage(const char* path) {
    SDL_Surface* not_optimized = IMG_Load(path);
    SDL_Surface* optimized = nullptr;
    if(nullptr == ServiceLocator::getScreen()) {
      return not_optimized;
    }
    optimized = SDL_ConvertSurface(not_optimized,
                                   ServiceLocator::getScreen()->getScreenSurface()->format,
                                   0);
    SDL_FreeSurface(not_optimized);
    return optimized;
  }

  static SDL_Surface* loadImage(const std::string path) {
    return ResourceManager::loadImage(path.c_str());
  }
private:
  std::map<std::string, std::shared_ptr<SDL_Surface> > v_res;
};

#endif
