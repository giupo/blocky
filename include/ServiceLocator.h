#ifndef __SERVICE_LOCATOR__
#define __SERVICE_LOCATOR__

#include "config4cpp/Configuration.h"

using config4cpp::Configuration;

class ServiceLocator {
public:
  static void provide(Configuration* cfg) {
    cfg_ = cfg;
  }
  
  static Configuration& getConfiguration() {
    return *cfg_;
  }
private:
  static Configuration* cfg_;
};

#endif
