
#include "blocky_main.h"
#include "bulky_logging.h"
#include "spdlog/spdlog.h"

int main(int argc, char** argv) {
  bootstrap_logging();
  auto log = spdlog::get("main");
  log->info("Hello World!");
  blocky_main(argc, argv);
  log->info("Done.");
  return 0;
}
