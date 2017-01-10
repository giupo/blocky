#include "component_factories.h"
#include "easylogging++.h"
#include "component.h"

void setupCreators() {
   creators_map.emplace("test_me", &test_me);
}
