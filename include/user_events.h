#ifndef __USER_EVENTS_H__
#define __USER_EVENTS_H__

#include <SDL2/SDL.h>
#include "easylogging++.h"

class GameEvents {
public:
  static Uint32 CHANGE_STATE;
  static int setupEvents() {

    GameEvents::CHANGE_STATE = SDL_RegisterEvents(1);
    LOG(INFO) << "Registered Event (" << GameEvents::CHANGE_STATE << ")";
    if (GameEvents::CHANGE_STATE == ((Uint32)-1)){
      LOG(ERROR) << "Cannot register events: " << SDL_GetError();
      return 1;
    }
    
    return 0;
  }
};

#endif 