#include "gtest/gtest.h"
#include "logging.h"

TEST (ComponentFactoryInit, InitWorksAsExpected) {
  EXPECT_EQ(0, 0);
  EXPECT_GE(1, 0);
}

int main(int argc, char **argv) {
  bootstrap_logging();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
