#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <SDL2/SDL.h>

#include "tinyxml2.h"
#include "easylogging++.h"
#include "service_locator.h"
#include "chipmunk.h"

class GameState {
public:
  virtual void init() {}
  virtual void init(tinyxml2::XMLNode* configNode) {}
  virtual ~GameState() {}
 
  virtual void render() =0;

  virtual void update() {
    this->render();
  }
  
  virtual void shutdown() {
    LOG(INFO) << "Shutting down state";
  }
};


class DoNothingState: public GameState {
private:
  SDL_Renderer* renderer;
public:

  virtual ~DoNothingState() {}
  
  virtual void init() {
    renderer = ServiceLocator::getScreen()->getRenderer();
  }
  virtual void render() {
    LOG(DEBUG) << "Do nothing!";
    SDL_RenderClear(renderer);
  }
};


class MenuGameState: public GameState {
private:
  SDL_Texture* texture;
  SDL_Renderer* renderer;
public:
  virtual ~MenuGameState() {}
  virtual void init(tinyxml2::XMLNode *configNode);
  virtual void render();
  virtual void update();
};


class SinglePlayerGameState: public GameState {
private:
  cpSpace* space;
  SDL_Renderer* renderer;
public:
  virtual ~SinglePlayerGameState() {}
  virtual void init(tinyxml2::XMLNode *configNode);
  virtual void update();
  virtual void shutdown();
  virtual void render();
};

#endif
