#include "ServiceLocator.h"
#include <iostream>
#include "logging.h"
#include "spdlog/spdlog.h"

#include "config4cpp/Configuration.h"
#include "config4cpp/ConfigurationException.h"

/** 
 * @brief init the logging system
 */
using config4cpp::Configuration;
using config4cpp::ConfigurationException;

void bootstrap_logging() {
  Configuration& cfg = ServiceLocator::getConfiguration();
  const char** systems;
  try {
    int num_systems = cfg.lookupInt("logging", "num_systems");
    cfg.lookupList("logging", "systems", systems, num_systems);
    
    for (int i = 0; i < num_systems; i++) {
      spdlog::stdout_color_mt(systems[i]);
    }
    
    int level = cfg.lookupInt("logging", "level");
    if (level == 0) {
      spdlog::set_level(spdlog::level::debug);
    } else {
      spdlog::set_level(spdlog::level::info);
    }
    
    // spdlog::stdout_color_mt("main");
    // spdlog::stdout_color_mt("Game");
  } catch( const ConfigurationException& ex) {
    std::cout << "bootstrap logging error: " << ex.c_str() << std::endl;
  }  
}

/**
 * @brief closes and release all loggers
 */

void close_logging() {
  spdlog::drop_all();
}

