#include "game.h"

#include <SDL2/SDL.h>

#include "service_locator.h"
#include "message_queue.h"
#include "tinyxml2.h"
#include "actor.h"
#include "component_factories.h"
#include "actor_factory.h"
#include "easylogging++.h"


Game::~Game() {  
  ServiceLocator::shutdown();
  SDL_Quit();
}

int Game::init(tinyxml2::XMLNode *node) {
  tinyxml2::XMLElement* ele = node->ToElement();

  int width = ele->IntAttribute("width");
  int height = ele->IntAttribute("height");

  LOG(DEBUG) << "[XML] width: " << width << ", height: " << height;

  if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    LOG(ERROR) << "Cannot init SDL: " << SDL_GetError();
    return 1;
  }
  
  ServiceLocator::getScreen()->init(width, height);
  return 0;
}

int Game::loop() {
  quit = false;
  SDL_Event e;
  while(!quit) {
    while( SDL_PollEvent( &e ) != 0 ) {
        //User requests quit
      if( e.type == SDL_QUIT ) {
        LOG(DEBUG) << "Got a QUIT message";
        quit = true;
      }
    }
  }
  ServiceLocator::getScreen()->update();
  return 0;
}
