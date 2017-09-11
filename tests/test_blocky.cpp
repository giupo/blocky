#include <cstdlib>

#include "gtest/gtest.h"
#include "logging.h"
#include "Config.h"

TEST (ComponentFactoryInit, InitWorksAsExpected) {
  EXPECT_EQ(0, 0);
  EXPECT_GE(1, 0);
}

int main(int argc, char **argv) {
  if(!Config::setup()) {
    return 1;
  }
  bootstrap_logging();
  ::testing::InitGoogleTest(&argc, argv);
  atexit(ServiceLocator::shutdown);
  
  return RUN_ALL_TESTS();
}
