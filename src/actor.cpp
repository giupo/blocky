#include "actor.h"

#include <vector>
#include "tinyxml2.h"
#include "message_queue.h"
#include "component_factories.h"

Actor::~Actor() {
  delete components;
}

int Actor::init(tinyxml2::XMLNode* node) {
}

int Actor::destroy() {
}

void Actor::onMessage(Message& msg) {
}

void Actor::update() {
}
