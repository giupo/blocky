#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include <map>
#include <string>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "screen.h"
#include "service_locator.h"
#include "spdlog/spdlog.h"


/**
 * @brief Allocates and deallocates Resources.
 *
 * References data based on names
 * 
 * I had to design this class because I'm still
 * an incompetent at circular references and software
 * design :) 
 * WILL be refactored soon
 * FIXME: refactor me
 */
class ResourceManager {
public:
  ~ResourceManager() {
    v_res.clear();
    v_tex.clear();
  }
  
  static SDL_Texture* loadTexture(std::string path) {
    return ResourceManager::loadTexture(path.c_str());
  }
  
  static SDL_Texture* loadTexture(const char* path) {
    auto log = spdlog::get("main");
    SDL_Surface* not_optimized = IMG_Load(path);
    SDL_Texture* texture = NULL;
    if( NULL == not_optimized ) {
      log->error("Unable to load image %s! SDL_image Error: %s", path, IMG_GetError());
    } else {
      //Create texture from surface pixels
      SDL_Renderer* renderer = ServiceLocator::getScreen()->getRenderer();
      texture = SDL_CreateTextureFromSurface( renderer, not_optimized );
      if( NULL == texture ) {
        log->error("Unable to create texture from %s! SDL Error: %s", path, SDL_GetError());
      }
      //Get rid of old loaded surface
      SDL_FreeSurface( not_optimized );
    }
    
    return texture;
  }
  
  static ResourceManager& instance() {
    static ResourceManager *instance = new ResourceManager();
    return *instance;
  }

private:
  ResourceManager() : v_res(), v_tex() {}
  std::map<std::string, std::shared_ptr<SDL_Surface> > v_res;
  std::map<std::string, std::shared_ptr<SDL_Texture> > v_tex;
};

#endif
