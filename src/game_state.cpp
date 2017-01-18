#include "game_state.h"

#include "tinyxml2.h"
#include "resource.h"
#include "service_locator.h"
#include "user_events.h"
#include "chipmunk.h"

void MenuGameState::init(tinyxml2::XMLNode *configNode) {
  this->texture = ResourceManager::loadTexture("texture.png");
  if (this->texture == NULL) {
    LOG(ERROR) << "Texture is Null";
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

void SinglePlayerGameState::init(tinyxml2::XMLNode *configNode) {
  LOG(DEBUG) << "SinglePlayerGameState.init";
  this->renderer = ServiceLocator::getScreen()->getRenderer();
  space = cpSpaceNew();
  cpSpaceSetGravity(space, cpv(.0,.0));
}

void SinglePlayerGameState::update() {
  cpSpaceStep(space, 1.0f/60.0f);
  this->render();
}

void SinglePlayerGameState::render(){
  LOG(DEBUG) << "SinglePlayerGameState.render";
  
  SDL_RenderClear( renderer );
  //Render texture to screen
  //SDL_RenderCopy( renderer, texture, NULL, NULL );
}

void SinglePlayerGameState::shutdown() {
  LOG(DEBUG) << "SinglePlayerGameState.shutdown";
  cpSpaceFree(space);
}
