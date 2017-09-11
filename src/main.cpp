
#include "logging.h"
#include "spdlog/spdlog.h"

#include "config4cpp/Configuration.h"
#include "config4cpp/ConfigurationException.h"

#include "Config.h"
#include "ServiceLocator.h"
#include "Game.h"

using config4cpp::Configuration;
using config4cpp::ConfigurationException;

int main(int argc, char** argv) {
  if(!Config::setup()) {
    return 1;
  }
  bootstrap_logging();

  auto log = spdlog::get("main");
  log->info("Starting blocky");

  BlockyGame game;
  game.init();
  game.loop();
  game.shutdown();

  ServiceLocator::shutdown();
  log->info("Done blocky.");
  return 0;
}
