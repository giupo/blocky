#include <locale.h>
#include <iostream>

#include "Config.h"

using config4cpp::Configuration;
using config4cpp::ConfigurationException;

bool Config::setup() {
  setlocale(LC_ALL, "");
  Configuration* cfg = Configuration::create();

  try {
    cfg->parse("config.cfg");
  } catch(const ConfigurationException& ex) {
    std::cout << "Can't parse config.cfg: " << ex.c_str() << std::endl;
    cfg->destroy();
    return false;
  }

  ServiceLocator::provide(cfg);
  return true;
}
