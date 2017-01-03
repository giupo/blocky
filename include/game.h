#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>

#include "message_queue.h"
#include "tinyxml2.h"
#include "easylogging++.h"

class Screen {
private:
  SDL_Window* window;
  SDL_Renderer* renderer;

  int width_, height_;
  
public:
  Screen(int width, int height): width_(width), height_(height) {
    window = nullptr;
    renderer = nullptr;
  }

  void setWidth(unsigned int width) {
    width_ = width;
  }

  void setHeight(unsigned int height) {
    height_ = height;
  }
  
  int init();
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

class Game {
private:
  Screen screen;
public:
  Game(): screen(0, 0) {}
  Game(int width, int height): screen(width, height) {}
  ~Game();
  
  int init(tinyxml2::XMLNode *node);
  int loop();
};

#endif
