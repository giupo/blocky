
#include <locale.h>
#include <iostream>

#include "logging.h"
#include "spdlog/spdlog.h"

#include "config4cpp/Configuration.h"
#include "config4cpp/ConfigurationException.h"

#include "ServiceLocator.h"
#include "Game.h"

using config4cpp::Configuration;
using config4cpp::ConfigurationException;

int main(int argc, char** argv) {
  setlocale(LC_ALL, "");
  config4cpp::Configuration* cfg = Configuration::create();

  try {
    cfg->parse("config.cfg");
  } catch(const ConfigurationException& ex) {
    std::cout << "Can't parse config.cfg: " << ex.c_str() << std::endl;
    cfg->destroy();
    return 1;
  }
  
  ServiceLocator::provide(cfg);  

  bootstrap_logging();

  auto log = spdlog::get("main");
  log->info("Starting blocky");

  BlockyGame game;
  game.init(cfg);
  game.loop();
  game.shutdown();

  cfg->destroy();
  log->info("Done blocky.");
  return 0;
}
