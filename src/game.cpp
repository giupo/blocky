#include "game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "service_locator.h"
#include "message_queue.h"
#include "tinyxml2.h"
#include "actor.h"
#include "component_factories.h"
#include "actor_factory.h"
#include "easylogging++.h"


Game::~Game() {  
  ServiceLocator::shutdown();
  IMG_Quit();
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

  IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
  
  if(0 != ServiceLocator::getScreen()->init(width, height)) {
    LOG(ERROR) << "Something went wrong with Screen init...";
  };
  return 0;
}

int Game::loop() {
  timer.start();
  quit = false;
  SDL_Event event;
  while(!quit) {
    unsigned int tick = timer.get_ticks();
    while( SDL_PollEvent( &event ) != 0 ) {
        //User requests quit
      if( event.type == SDL_QUIT ) {
        LOG(DEBUG) << "Got a QUIT message";
        quit = true;
      }

      if( event.type == SDL_KEYDOWN ) {
	//If enter was pressed
	if( event.key.keysym.sym == SDLK_SPACE || 	\
	    event.key.keysym.sym == SDLK_RETURN) {
	  //Turn frame rate regulator on/off
	  LOG(DEBUG) << "Switching cap";
	  cap = (!cap) ;
	}
      }
    }

    ServiceLocator::getScreen()->update();
    //If we want to cap the frame rate

    unsigned int elapsed = timer.get_ticks() - tick;
    LOG(DEBUG) << "Elapsed: " << elapsed << ", cap=" << cap;
    if( ( cap == true ) && ( elapsed < (1000 / fps) ) ) {
      Uint32 delay = 1000/fps - elapsed;
      LOG(DEBUG) << "Capping out for " << delay;
      SDL_Delay( delay );
    }
  }
 
  return 0;
}
