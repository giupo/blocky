#include "component_factories.h"
#include "easylogging++.h"
#include "component.h"

FunctionMap creators_map;

BComponent* test_me() {
  return nullptr;
}

void ComponentFactory::init() {
  LOG(DEBUG) << "Setting up Creators";
  creators_map.emplace("test_me", &test_me);
  LOG(DEBUG) << "Setup Creators Completed";  
}
