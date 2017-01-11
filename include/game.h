#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>

#include "message_queue.h"
#include "tinyxml2.h"
#include "easylogging++.h"

class Game {
private:
  bool quit;
public:
  Game(): quit(false) {
  }
                               
  ~Game();
  
  int init(tinyxml2::XMLNode *node);
  int loop();
};

#endif
