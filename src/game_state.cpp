#include "game_state.h"

#include "tinyxml2.h"
#include "resource.h"
#include "service_locator.h"
#include "user_events.h"

void DoNothingState::update() {
  SDL_Renderer* renderer = ServiceLocator::getScreen()->getRenderer();
  SDL_RenderClear( renderer );
}

void MenuGameState::init(tinyxml2::XMLNode *configNode) {
  this->texture = ResourceManager::loadTexture("texture.png");
  if (this->texture == NULL) {
    LOG(ERROR) << "Texture is Null";
  }
}

void MenuGameState::update() {
  LOG(INFO) << "Texture is null?" << (texture == NULL);
  //Clear screen
  SDL_Renderer* renderer = ServiceLocator::getScreen()->getRenderer();
  SDL_RenderClear( renderer );
  //Render texture to screen
  SDL_RenderCopy( renderer, texture, NULL, NULL );
}

