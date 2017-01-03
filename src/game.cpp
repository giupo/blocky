#include "game.h"

#include "service_locator.h"
#include "message_queue.h"
#include "tinyxml2.h"
#include "actor.h"
#include "component_factories.h"
#include "actor_factory.h"

Game::Game() {
}

Game::~Game() {
  ServiceLocator::shutdown();
}

int Game::init(tinyxml2::XMLNode *node) {
   // setup ServiceLocator
  ServiceLocator::provide(new ActorFactory());
  ServiceLocator::provide(new MessageQueue());
  return 0;
}

int Game::loop() {
  return 0;
}
