#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>
#include "timer.h"
#include "message_queue.h"
#include "tinyxml2.h"
#include "easylogging++.h"

class Game {
private:
  bool quit;
  unsigned int fps;
  bool cap;
  Timer timer;
public:
  Game(bool cap_, unsigned int fps_): cap(cap_), quit(false), fps(fps_), timer() {
  }
                               
  ~Game();
  
  int init(tinyxml2::XMLNode *node);
  int loop();
};

#endif
