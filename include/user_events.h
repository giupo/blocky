#ifndef __USER_EVENTS_H__
#define __USER_EVENTS_H__

#include <SDL2/SDL.h>
#include "spdlog/spdlog.h"

class GameEvents {
public:
  static Uint32 CHANGE_STATE;
  static int setupEvents() {
    
    GameEvents::CHANGE_STATE = SDL_RegisterEvents(1);
    spdlog::get("main")->info("Registered Event ({})", GameEvents::CHANGE_STATE);
    if (GameEvents::CHANGE_STATE == ((Uint32)-1)){
      spdlog::get("main")->error("Cannot register events: {}", SDL_GetError());
      return 1;
    }
    
    return 0;
  }
};

#endif 
