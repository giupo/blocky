#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <SDL2/SDL.h>
#include <config4cpp/Configuration.h>
#include "spdlog/spdlog.h"
#include "service_locator.h"
#include "world.h"

using config4cpp::Configuration;

class GameState {
public:
  virtual void init() {
    Configuration* cfg = ServiceLocator::getConfiguration();
    this->init(cfg);
  }
  
  virtual void init(Configuration* cfg) =0;
  virtual ~GameState() {}
 
  virtual void render() =0;
  virtual void update() =0;
  
  virtual void shutdown() {
    spdlog::get("main")->info("Shutting down state");
  }
};


class DoNothingState: public GameState {
private:
  SDL_Renderer* renderer;
public:
  
  virtual ~DoNothingState() {}
  virtual void update() {}
  virtual void init(Configuration* cfg) {
    renderer = ServiceLocator::getScreen()->getRenderer();
  }
  
  virtual void render() {
    spdlog::get("main")->debug("Do nothing!");
    SDL_RenderClear(renderer);
  }
};


class MenuGameState: public GameState {
private:
  SDL_Texture* texture;
  SDL_Renderer* renderer;
public:
  virtual ~MenuGameState() {}
  virtual void init(Configuration* cfg);
  virtual void render();
  virtual void update();
};


class SinglePlayerGameState: public GameState {
private:
  World* world;
  SDL_Renderer* renderer;
public:
  SinglePlayerGameState(): world(nullptr), renderer(nullptr) {}
  virtual ~SinglePlayerGameState() {
    this->shutdown();
  }
  virtual void init(Configuration* cfg);
  virtual void update();
  virtual void shutdown();
  virtual void render();
};

#endif
