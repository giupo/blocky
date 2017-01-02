#include <iostream>
#include "blocky_main.h"
#include "blocky_config.h"
#include "bulky_logging.h"
#include "easylogging++.h"

int main(int argc, char** argv) {
  bootstrap_logging();
  LOG(DEBUG) << "Starting blocky version " << VERSION;
  blocky_main(argc, argv);
  LOG(INFO) << "Bye Bye!";
  return 0;
}
