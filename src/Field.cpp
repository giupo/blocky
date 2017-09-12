#include "Field.h"

#include "spdlog/spdlog.h"

Field::Field() {
  auto log = spdlog::get("Field");
  log->debug("init");
  log->debug("init completed");
}

Field::~Field() {
}
