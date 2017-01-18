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
#include "user_events.h"

Game::~Game() {  
  ServiceLocator::shutdown();
  IMG_Quit();
  SDL_Quit();
}


/** 
 * @brief initialize the Game
 * 
 * @param node Config Node from XML (to be refactored)
 * 
 * @return 0 for success, anything else for failure
 */

int Game::init(tinyxml2::XMLNode *node) {
  this->node = node;
  tinyxml2::XMLElement* ele = node->ToElement();
  
  int width = ele->IntAttribute("width");
  int height = ele->IntAttribute("height");

  LOG(DEBUG) << "[XML] width: " << width << ", height: " << height;

  if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    LOG(ERROR) << "Cannot init SDL: " << SDL_GetError();
    return 1;
  }

  
  if(GameEvents::setupEvents() != 0) {
    return 1;
  }
  
  IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

  if(0 != ServiceLocator::getScreen()->init(width, height)) {
    LOG(ERROR) << "Something went wrong with Screen init...";
  };

  GameState* menu = new MenuGameState();
  menu->init(node);
  this->changeState(menu);
  return 0;
}

/** 
 * @brief changes state of the Game
 * 
 * @param other_state 
 */

void Game::changeState(GameState* other_state) {
  if (this->state != nullptr) {
    state->shutdown();
    delete state;
  }
  this->state = other_state;
}


/** 
 * @brief Main game loop
 * 
 * 
 * @return 0 if no errors are found, !=0 otherwise 
 */

int Game::loop() {
  timer.start();
  quit = false;
  while(!quit) {
    processMessages();
    state->update();
    ServiceLocator::getScreen()->render();
  }
  return 0;
}


/** 
 * @brief Request a different game state throught SDL's queue
 * 
 * @param state state requested (implementing GameState)
 */

void Game::requestState(GameState* state) {
  SDL_Event changeEvent;
  SDL_memset(&changeEvent, 0, sizeof(changeEvent));
  changeEvent.type = GameEvents::CHANGE_STATE;
  changeEvent.user.data1 = (void*) state;
  changeEvent.user.data2 = 0;
  SDL_PushEvent(&changeEvent);
}


/** 
 * @brief Processes messages from queue and input from user
 * 
 * @return an int for future usage (unused so far) 
 */

int Game::processMessages() {
  SDL_Event event;
  while( SDL_PollEvent( &event ) != 0 ) {
      
    //User requests quit
    if( event.type == SDL_QUIT ) {
      LOG(DEBUG) << "Got a QUIT message";
      quit = true;
    }
    
    if ( event.type >= GameEvents::CHANGE_STATE ) {
      LOG(DEBUG) << "Change State!";
      this->changeState((GameState*) event.user.data1);
    }
    
    if( event.type == SDL_KEYDOWN ) {
      if( event.key.keysym.sym == SDLK_SPACE ||     \
          event.key.keysym.sym == SDLK_RETURN ) {
        LOG(DEBUG) << "Switching cap";
        cap = (!cap) ;
      }
      
      if( event.key.keysym.sym == SDLK_q ) {
        quit = true;
      }
      
      if( event.key.keysym.sym == SDLK_w ) {
        GameState* state = new DoNothingState();
        state->init();
        this->requestState(state);
      }
      
      if ( event.key.keysym.sym == SDLK_s) {
        MenuGameState* state = new MenuGameState();
        state->init(this->node);
        this->requestState(state);
      }

      if ( event.key.keysym.sym == SDLK_1 ) {
        SinglePlayerGameState* state = new SinglePlayerGameState();
        state->init(this->node);
        this->requestState(state);
      }
    }
  }
  
  return 0;
}
