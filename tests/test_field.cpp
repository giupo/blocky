#include <cstdlib>

#include "gtest/gtest.h"
#include "logging.h"
#include "Field.h"
#include "Config.h"

TEST (Field, InitWorksAsExpected) {
  Field field;
  for(int i=0; i<NUM_ROWS; ++i) {
    for(int j=0; j<NUM_COLS; ++j) {
      EXPECT_EQ(field.grid[i][j], 0);
    }
  }
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
