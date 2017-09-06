#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>
#include <config4cpp/Configuration.h>

#include "timer.h"
#include "message_queue.h"
#include "game_state.h"

using config4cpp::Configuration;

class Game {
private:
  bool quit;
  unsigned int fps;
  bool cap;
  Timer timer;
  GameState* state;
public:
  Game(bool cap_, unsigned int fps_): \
    cap(cap_), quit(false), fps(fps_), timer() {
    state = nullptr;
  }
                               
  ~Game();
  void requestState(GameState* state);
  void changeState(GameState* other_state);
  int init(Configuration* cfg);
  int processMessages();
  int loop();
};

#endif
