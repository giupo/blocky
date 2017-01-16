#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "screen.h"

#include "easylogging++.h"
#include "game.h"

#include "tinyxml2.h"
#include "service_locator.h"
#include "resource.h"


int Screen::init(unsigned int width, unsigned height) {
  LOG(DEBUG) << "Init Screen";
  width_ = width;
  height_ = height;
  if(width_ == 0 || height_ == 0) {
    LOG(DEBUG) << "Screen width/height is not set," <<	\
      "taking all the width available";
    SDL_DisplayMode current;
    // the 0 here is for the first display available
    int should_be_zero = SDL_GetCurrentDisplayMode(0, &current); 
    if(should_be_zero != 0) {
      LOG(ERROR) << "Could not get display mode for video display 0: " << \
        SDL_GetError();
      return -1;
    }
    
    if(width_ == 0) {
      width_ = current.w;
      LOG(DEBUG) << "New width: " << width_;
    }
    
    if(height_ == 0) {
      height_ = current.h;
      LOG(DEBUG) << "New height: " << height_;
    }
  }
  
  window = SDL_CreateWindow("Blocky", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
			    width_, height_,
                            SDL_WINDOW_SHOWN);
  if(window == NULL) {
    LOG(ERROR) << "Window could not be created! SDL Error: " << SDL_GetError();
    return -1;
  } else {
    // screenSurface = SDL_GetWindowSurface(window);
    // Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    
    if(renderer == NULL) {
      LOG(ERROR) << "Renderer could not be created! SDL Error: " << SDL_GetError();
      return -1;
    }
  }
  ResourceManager& rm = ResourceManager::instance();
  texture = ResourceManager::loadTexture("img.jpg");
  LOG(DEBUG) << "Init Screen complete";
  return 0;
}

void Screen::update() {
  //Clear screen
  SDL_RenderClear( renderer );
  
  //Render texture to screen
  SDL_RenderCopy( renderer, texture, NULL, NULL );
  
  //Update screen
  SDL_RenderPresent( renderer );
}
