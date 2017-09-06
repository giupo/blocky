#include <iostream>

#include <SDL2/SDL.h>
#include <chipmunk/chipmunk.h>

#include <config4cpp/Configuration.h>

#if defined(__LINUX__) || defined(__APPLE__)
#include <csignal>
#endif

#include <map>

#include "blocky_main.h"
#include "game.h"

#include "blocky_macros.h"

#include "component_factories.h"
#include "actor_factory.h"
#include "service_locator.h"
#include "screen.h"
#include "spdlog/spdlog.h"

using config4cpp::Configuration;

/**
 * @brief App main entry
 */

int blocky_main(int argc, char **argv) {
  //Setup Service Locator:
  ServiceLocator::provide(new ComponentFactory());
  ServiceLocator::provide(new MessageQueue());
  ServiceLocator::provide(new ActorFactory());
  ServiceLocator::provide(new Screen());
  ServiceLocator::provide(Configuration::create());
  ServiceLocator::getComponentFactory()->init();

  Game g(true, 120);

  Configuration* cfg = ServiceLocator::getConfiguration();
  if(g.init(cfg)) {
    spdlog::get("main")->error("Cannot init game with current configuration");
  }
  int rc = g.loop();
  return rc;
}


