#include "game.h"

#include <SDL2/SDL.h>

#include "service_locator.h"
#include "message_queue.h"
#include "tinyxml2.h"
#include "actor.h"
#include "component_factories.h"
#include "actor_factory.h"
<<<<<<< HEAD
#include "easylogging++.h"

int Screen::init() {
  LOG(DEBUG) << "Init Screen";

  if(width_ == 0 || height_ == 0) {
    LOG(DEBUG) << "Screen width/height is not set, taking all the width available";
    SDL_DisplayMode current;
    // the 0 here is for the first display available
    int should_be_zero = SDL_GetCurrentDisplayMode(0, &current); 
    if(should_be_zero != 0) {
      LOG(ERROR) << "Could not get display mode for video display 0: " << \
        SDL_GetError();
      return -1;
    }
=======
>>>>>>> merged

    if(width_ == 0) {
      width_ = current.w;
      LOG(DEBUG) << "New width: " << width_;
    }
    
    if(height_ == 0) {
      height_ = current.h;
      LOG(DEBUG) << "New height: " << height_;
    }
  }
  
  window = SDL_CreateWindow("Blocky",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            width_, height_,
                            SDL_WINDOW_SHOWN);
  if(window == NULL) {
    LOG(ERROR) << "Window could not be created! SDL Error: " << SDL_GetError();
    return -1;
  } else {
    //Create renderer for window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if(renderer == NULL) {
      LOG(ERROR) << "Renderer could not be created! SDL Error: " << SDL_GetError();
      return -1;
    }
  }
  LOG(DEBUG) << "Init Screen complete";
  return 0;
}

<<<<<<< HEAD

Game::~Game() {  
  ServiceLocator::shutdown();
  SDL_Quit();
}

int Game::init(tinyxml2::XMLNode *node) {
  tinyxml2::XMLElement* ele = node->ToElement();

  int width = ele->IntAttribute("width");
  int height = ele->IntAttribute("height");
  if(width != 0) {
    screen.setWidth(width);
  }
  if(height != 0) {
    screen.setHeight(height);
  }
  LOG(DEBUG) << "[XML] width: " << width << ", height: " << height;

  if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    LOG(ERROR) << "Cannot init SDL: " << SDL_GetError();
    return 1;
  }
  screen.init();
  // setup ServiceLocator
  LOG(DEBUG) << "Setup ServiceLocator";
=======
Game::~Game() {
  ServiceLocator::shutdown();
}

int Game::init(tinyxml2::XMLNode *node) {
   // setup ServiceLocator
>>>>>>> merged
  ServiceLocator::provide(new ActorFactory());
  ServiceLocator::provide(new MessageQueue());
  
  return 0;
}

int Game::loop() {
  return 0;
}
