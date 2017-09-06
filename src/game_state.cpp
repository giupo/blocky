#include "game_state.h"

#include <config4cpp/Configuration.h>

#include "resource.h"
#include "service_locator.h"
#include "user_events.h"
#include "chipmunk/chipmunk.h"
#include "world.h"
#include "spdlog/spdlog.h"

using config4cpp::Configuration;


void MenuGameState::init(Configuration* cfg) {
  this->texture = ResourceManager::loadTexture("texture.png");
  if (this->texture == NULL) {
    spdlog::get("main")->error("Texture is Null");
  }
  this->renderer = ServiceLocator::getScreen()->getRenderer();
}


void MenuGameState::update() {
  this->render();
}


void MenuGameState::render() {
  //Clear screen
  SDL_RenderClear( renderer );
  //Render texture to screen
  SDL_RenderCopy( renderer, texture, NULL, NULL );
}


void SinglePlayerGameState::init(Configuration* cfg) {
  spdlog::get("main")->debug("SinglePlayerGameState.init");
  this->renderer = ServiceLocator::getScreen()->getRenderer();
  world = new World();
  world->init(cfg);
}


void SinglePlayerGameState::update() {
  world->update();
}


void SinglePlayerGameState::render(){
  spdlog::get("main")->debug("SinglePlayerGameState.render");
  SDL_RenderClear( renderer );
}


void SinglePlayerGameState::shutdown() {
  spdlog::get("main")->debug("SinglePlayerGameState.shutdown");
  if (nullptr != world) {
    world->shutdown();
    delete world;
    world = nullptr;
  }
}
