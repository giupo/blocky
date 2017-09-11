#ifndef __CONFIG__
#define __CONFIG__

#include "ServiceLocator.h"
#include "config4cpp/Configuration.h"
#include "config4cpp/ConfigurationException.h"

namespace Config {
  /**
   * @brief Setup config for application and tests
   * @return `false` if setup fails, `true` otherwise
   */
  bool setup();
};

#endif
