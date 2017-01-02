#include "bulky_logging.h"
#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

int bootstrap_logging() {
  el::Configurations defaultConf;
  defaultConf.setToDefault();
  // Values are always std::string
  defaultConf.set(el::Level::Info, 
                  el::ConfigurationType::Format, "%datetime %level %msg");
  // default logger uses default configurations
  el::Loggers::reconfigureLogger("default", defaultConf);
  LOG(INFO) << "Log using default file";

  return 0;
}
