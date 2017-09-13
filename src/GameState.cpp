#include "GameState.h"
#include "Game.h"

#include "ServiceLocator.h"

#include "SDL2/SDL.h"
#include "SDL_image.h"

#include "spdlog/spdlog.h"
#include "config4cpp/Configuration.h"
#include "config4cpp/ConfigurationException.h"

using config4cpp::Configuration;
using config4cpp::ConfigurationException;

void MainMenuState::init() {
  auto log = spdlog::get("MainMenuState");
  log->debug("init");
  Configuration& cfg = ServiceLocator::getConfiguration();
  SDL_Renderer* renderer = ServiceLocator::getRenderer();

  SDL_Surface* background_surface = IMG_Load(
     cfg.lookupString("Game", "Menu.background"));

  background_texture = SDL_CreateTextureFromSurface(renderer, background_surface);
  SDL_FreeSurface(background_surface);
  log->debug("init complete");
}

void MainMenuState::handleInput() {
  auto log = spdlog::get("MainMenuState");
  SDL_Event event;
  if( SDL_PollEvent(&event) ) {
    if (event.type == SDL_QUIT) {
      this->game->setRunning(false);
    } else if( event.type == SDL_KEYDOWN ) {
      //Select surfaces based on key press
      switch( event.key.keysym.sym ) {
      case SDLK_q:
	this->game->setRunning(false);
	break;
      case SDLK_s:
	log->debug("requesting state from MainMenu");
	GameState* state = new SinglePlayerState(this->game);
	this->game->requestState(state);
      }
    }
  }
}

void MainMenuState::update() {
  auto log = spdlog::get("MainMenuState");
  SDL_Renderer* renderer = ServiceLocator::getRenderer();
  SDL_RenderCopy(renderer, background_texture, NULL, NULL);
}

void MainMenuState::shutdown() {
  auto log = spdlog::get("MainMenuState");
  log->debug("shutdown started");
  SDL_DestroyTexture(background_texture);
  log->debug("shutdown completed");
}


void SinglePlayerState::init() {
  auto log = spdlog::get("SinglePlayerState");
  log->debug("init");
  Configuration& cfg = ServiceLocator::getConfiguration();
  SDL_Renderer* renderer = ServiceLocator::getRenderer();
  
  SDL_Surface* background_surface = IMG_Load(
    cfg.lookupString("Game", "Menu.background"));
  
  background = SDL_CreateTextureFromSurface(renderer, background_surface);
  SDL_FreeSurface(background_surface);
  this->matrix = new Matrix(NUM_ROWS, NUM_COLS);
  
  log->debug("init complete");
}

void SinglePlayerState::handleInput() {
  auto log = spdlog::get("SinglePlayerState");
  SDL_Event event;
  if( SDL_PollEvent(&event) ) {
    if (event.type == SDL_QUIT) {
      this->game->setRunning(false);
    } else if( event.type == SDL_KEYDOWN ) {
      //Select surfaces based on key press
      switch( event.key.keysym.sym ) {
      case SDLK_q:
	this->game->setRunning(false);
	break;
      case SDLK_ESCAPE:
	log->debug("requesting state from SinglePlayerState");
	GameState* state = new MainMenuState(this->game);
	this->game->requestState(state);
      }
    }
  }
}

void SinglePlayerState::update() {
  auto log = spdlog::get("SinglePlayerState");
  SDL_Renderer* renderer = ServiceLocator::getRenderer();  
  SDL_RenderCopy(renderer, background, NULL, NULL);
}

void SinglePlayerState::shutdown() {
  auto log = spdlog::get("SinglePlayerState");
  SDL_DestroyTexture(background);
  delete matrix;
}

void SinglePlayerState::spawnPiece() {
  // pick a random piece from a set/list of pieces
  // set it to the next piece...
}
