#include "game_state.h"

#include "tinyxml2.h"
#include "resource.h"
#include "service_locator.h"
#include "user_events.h"

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

  SDL_Event event;
  SDL_memset(&event, 0, sizeof(event)); /* or SDL_zero(event) */
  event.type = GameEvents::DIOPORCO;
  event.user.code = 33;
  event.user.data1 = this;
  event.user.data2 = 0;
  SDL_PushEvent(&event);
}

