#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>
#include "timer.h"
#include "message_queue.h"
#include "tinyxml2.h"
#include "easylogging++.h"
#include "game_state.h"

class Game {
private:
  bool quit;
  unsigned int fps;
  bool cap;
  Timer timer;
  GameState* state;
  tinyxml2::XMLNode *node;
public:
  Game(bool cap_, unsigned int fps_): cap(cap_), quit(false), fps(fps_), timer() {
    state = nullptr;
  }
                               
  ~Game();
  void requestState(GameState* state);
  void changeState(GameState* other_state);
  int init(tinyxml2::XMLNode *node);
  int loop();
};

#endif
