#include "Game.h"
#include "GameState.h"
#include "ServiceLocator.h"

#include "SDL2/SDL.h"

#include "config4cpp/Configuration.h"
#include "config4cpp/ConfigurationException.h"

#include "spdlog/spdlog.h"

using config4cpp::Configuration;
using config4cpp::ConfigurationException;

void BlockyGame::init() {
  auto log = spdlog::get("Game");
  unsigned int width = 0;
  unsigned int height = 0;
  Configuration& cfg = ServiceLocator::getConfiguration();
  
  try {
    width = cfg.lookupInt("Game", "screen.width");
    height = cfg.lookupInt("Game", "screen.height");
  } catch (const ConfigurationException& ex) {
    log->error(ex.c_str());
    width = 640;
    height = 480;
  }
  //Will parse some config.
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("BlockyGame", 0, 0, width, height, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  ServiceLocator::provide(renderer);
  GameState* state = new MainMenuState(this);
  this->changeState(state);
}

void BlockyGame::requestState(GameState* newState) {
  this->nextState = newState;
}

void BlockyGame::changeState(GameState* newState) {
  auto log = spdlog::get("Game");
  log->debug("change state");
  GameState* old = this->state;
  this->state = newState;
  this->state->init();
  if (old != nullptr) {
    log->debug("old state wasn't null, shutting it down");
    old->shutdown();
  }
  delete old;
}

void BlockyGame::loop() {
  auto log = spdlog::get("Game");
  running = true;
  SDL_Event event;
  log->info("starting game loop");
  SDL_Renderer* renderer = ServiceLocator::getRenderer();
  while (running) {

    state->handleInput();

    SDL_RenderClear(renderer);
    state->update();
    SDL_RenderPresent(renderer);

    // handle state change here
    if (nullptr != this->nextState) {
      log->debug("next state isn't null, changing state...");
      changeState(this->nextState);
      nextState = nullptr;
    }
  }
  log->info("Ending game loop");
}

void BlockyGame::setRunning(bool running) {
  this->running = running;
}

void BlockyGame::shutdown() {
  this->setRunning(false);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
