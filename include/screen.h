#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <SDL2/SDL.h>
#include "easylogging++.h"

class Screen {
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Surface* screenSurface;
  unsigned int width_, height_;
  
public:
  Screen(): width_(0), height_(0) {
    window = nullptr;
    renderer = nullptr;
    screenSurface = nullptr;
  }
  
  void setWidth(unsigned int width) {
    width_ = width;
  }
  
  void setHeight(unsigned int height) {
    height_ = height;
  }

  unsigned int getWidth() {
    return width_;
  }

  unsigned int getHeight() {
    return height_;
  }

  SDL_Surface* getScreenSurface() {
    return screenSurface;
  }
  
  int init(unsigned int width, unsigned int height);
  void update();

  ~Screen() {
    LOG(DEBUG) << "Destroy Screen";
    if(renderer) {
      SDL_DestroyRenderer(renderer);
    }
    if(window) {
      SDL_DestroyWindow(window);
    }
    LOG(DEBUG) << "Screen destroyed";
  }
};

#endif
