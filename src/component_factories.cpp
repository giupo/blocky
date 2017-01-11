#include "component_factories.h"
#include "easylogging++.h"
#include "component.h"


BComponent* test_me() {
  return nullptr;
}

void setupCreators() {
   creators_map.emplace("test_me", &test_me);
}
