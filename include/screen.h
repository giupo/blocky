#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <SDL2/SDL.h>
#include "easylogging++.h"

class Screen {
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Texture* texture;
  unsigned int width_, height_;
  
public:
  Screen(): width_(0), height_(0) {
    window = nullptr;
    renderer = nullptr;
  }

  SDL_Renderer* getRenderer() {
    return renderer;
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

  int init(unsigned int width, unsigned int height);
  
  void update();

  ~Screen() {
    LOG(DEBUG) << "Destroy Screen";
    SDL_DestroyTexture(texture);
    if(nullptr != renderer) {
      SDL_DestroyRenderer(renderer);
    }

    if(nullptr != window) {
      SDL_DestroyWindow(window);
    }

    window = nullptr;
    renderer = nullptr;    

    LOG(DEBUG) << "Screen destroyed";
  }
};

#endif
