#include "actor.h"

#include <vector>

#include "tinyxml2.h"
#include "message_queue.h"
#include "component_factories.h"

Actor::Actor() {
  components = new std::vector<BComponent*>();
}

Actor::~Actor() {
  delete components;
}

int Actor::init(tinyxml2::XMLNode* node) {
  return 0;
}

int Actor::destroy() {
  return 0;
}

void Actor::onMessage(Message& msg) {
  
}

void Actor::update() {
  
}
