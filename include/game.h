#ifndef __GAME_H__
#define __GAME_H__

#include "message_queue.h"
#include "tinyxml2.h"
class Game {

 public:
  Game();
  ~Game();

  int init(tinyxml2::XMLNode *node);
  int loop();
};

#endif
