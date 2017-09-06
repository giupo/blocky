#include "bulky_logging.h"

#include "spdlog/spdlog.h"


/** 
 * @brief init the logging system
 */

int bootstrap_logging() {
  spdlog::set_level(spdlog::level::debug);
  spdlog::stdout_color_mt("main");
  return 0;
}


/**
 * @brief closes and release all loggers
 */

int close_logging() {
  spdlog::drop_all();
  return 0;
}
