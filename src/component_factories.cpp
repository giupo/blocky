#include "component_factories.h"
#include "spdlog/spdlog.h"
#include "component.h"

FunctionMap creators_map;

BComponent* test_me() {
  return nullptr;
}

void ComponentFactory::init() {
  spdlog::get("main")->debug("Setting up Creators");
  creators_map.emplace("test_me", &test_me);
  spdlog::get("main")->debug("Setup Creators Completed");
}
