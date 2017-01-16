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

  /*std::shared_ptr<SDL_Surface> getImage(const std::string name) {
    auto search = v_res.find(name);
    if(search == v_res.end()) {
      v_res[name] = std::shared_ptr<SDL_Surface>(ResourceManager::loadImage(name));
    }
    return v_res[name];
  }

  std::shared_ptr<SDL_Texture> getTexture(const std::string name) {
    auto search = v_tex.find(name);
    if(search == v_tex.end()) {
      v_tex[name] = std::shared_ptr<SDL_Texture>(ResourceManager::loadTexture(name));
    }
    return v_tex[name];
    }*/
  
  static SDL_Texture* loadTexture(std::string path) {
    return ResourceManager::loadTexture(path.c_str());
  }
  
  static SDL_Texture* loadTexture(const char* path) {
    SDL_Surface* not_optimized = IMG_Load(path);
    SDL_Texture* texture = NULL;
    if( NULL == not_optimized ) {
      LOG(ERROR) << "Unable to load image " << path		\
		 << "! SDL_image Error:" << IMG_GetError();
    } else {
      //Create texture from surface pixels
      SDL_Renderer* renderer = ServiceLocator::getScreen()->getRenderer();
      texture = SDL_CreateTextureFromSurface( renderer, not_optimized );
      if( NULL == texture ) {
	LOG(ERROR) << "Unable to create texture from " << path	\
		   << "! SDL Error: " << SDL_GetError();
      }
      //Get rid of old loaded surface
      SDL_FreeSurface( not_optimized );
    }
    
    return texture;
  }
  
  /*static SDL_Surface* loadImage(const char* path) {
    SDL_Surface* not_optimized = IMG_Load(path);
    SDL_Surface* optimized = nullptr;
    if(nullptr == ServiceLocator::getScreen()) {
      return not_optimized;
    }
    optimized = SDL_ConvertSurface(
       not_optimized,
       ServiceLocator::getScreen()->getScreenSurface()->format,
       0);
    SDL_FreeSurface(not_optimized);
    return optimized;
  }

  static SDL_Surface* loadImage(const std::string path) {
     return ResourceManager::loadImage(path.c_str());
  }*/

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
