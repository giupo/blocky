#include "game.h"

#include "service_locator.h"
#include "message_queue.h"
#include "tinyxml2.h"
#include "actor.h"
#include "component_factories.h"

Game::Game() {
}

Game::~Game() {
  MessageQueue* queue = ServiceLocator::getMessageQueue();
  delete queue;
}

int Game::init(tinyxml2::XMLNode *node) {
  
  ServiceLocator::provide(new MessageQueue());
  return 0;
}

int Game::loop() {
  return 0;
}
