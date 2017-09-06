#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "screen.h"

#include "spdlog/spdlog.h"
#include "game.h"

#include "tinyxml2.h"
#include "service_locator.h"


int Screen::init(unsigned int width, unsigned height) {
  auto log = spdlog::get("main");
  log->debug("Init Screen");
  width_ = width;
  height_ = height;
  if(width_ == 0 || height_ == 0) {
    log->debug("Screen width/height is not set,taking all the width available");
    SDL_DisplayMode current;
    // the 0 here is for the first display available
    int should_be_zero = SDL_GetCurrentDisplayMode(0, &current); 
    if(should_be_zero != 0) {
      log->error("Could not get display mode for video display 0: {}", SDL_GetError());
      return -1;
    }
    
    if(width_ == 0) {
      width_ = current.w;
      log->debug("New width: %d", width_);
    }
    
    if(height_ == 0) {
      height_ = current.h;
      log->debug("New height: %d", height_);
    }
  }
  
  window = SDL_CreateWindow("Blocky", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            width_, height_,
                            SDL_WINDOW_SHOWN);
  if(window == NULL) {
    log->error("Window could not be created! SDL Error: {}", SDL_GetError());
    return -1;
  } else {
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );    
    if(renderer == NULL) {
      log->error("Renderer could not be created! SDL Error: {}", SDL_GetError());
      return -1;
    }
  }
  
    
  log->debug("Init Screen complete");
  return 0;
}

void Screen::render() {
  SDL_RenderPresent( renderer );
}
