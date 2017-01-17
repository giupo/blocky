#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <SDL2/SDL.h>

#include "tinyxml2.h"
#include "easylogging++.h"

class GameState {
public:
  virtual void init() {}
  virtual void init(tinyxml2::XMLNode* configNode) {}
  virtual void update() =0;
  virtual void shutdown() {
    LOG(INFO) << "Shutting down state";
  }
};

class DoNothingState: public GameState {
public:
  virtual void update();
};

class MenuGameState: public GameState {
private:
  SDL_Texture* texture;
public:
  virtual void init(tinyxml2::XMLNode *configNode);
  virtual void update();
};

#endif
