#include "bulky_logging.h"
#include "easylogging++.h"
#include "tinyxml2.h"

INITIALIZE_EASYLOGGINGPP

int bootstrap_logging() {
  el::Configurations defaultConf;
  defaultConf.setToDefault();
  // Values are always std::string
  defaultConf.set(el::Level::Debug, el::ConfigurationType::Format,
                  "%datetime %level %msg");
  defaultConf.set(el::Level::Info, el::ConfigurationType::Format,
                  "%datetime %level %msg");
  // default logger uses default configurations
  el::Loggers::reconfigureLogger("default", defaultConf);
  LOG(DEBUG) << "Log debug";
  LOG(INFO) << "Log using default file";
  LOG(WARNING) << "Warn test";
  LOG(ERROR) << "Error test";
  return 0;
}
