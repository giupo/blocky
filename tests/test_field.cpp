#include <cstdlib>

#include "gtest/gtest.h"
#include "logging.h"
#include "Field.h"
#include "Config.h"

TEST(Matrix, LifeCycle) {
  Matrix matrix(NUM_ROWS, NUM_COLS);
  for(int i=0; i<NUM_ROWS; i++) {
    for(int j=0; j<NUM_COLS; j++) {
      EXPECT_EQ(*matrix.at(i, j), 0);
    }
  }
}

TEST(Matrix, subsetting) {
  Matrix matrix(NUM_ROWS, NUM_COLS);
  *matrix.at(1,1) = 10;
  *matrix.at(7, 8) = 10000;
  int expected = 0;
  for(int i=0; i < NUM_ROWS; i++) {
    for(int j=0; j < NUM_COLS; j++) {
      if (i == 1 && j== 1) {
	expected = 10;
      } else if (i == 7 && j == 8) {
	expected = 10000;
      } else { 
	expected = 0;
      }
      EXPECT_EQ(*matrix.at(i, j), expected);
    }
  }
}


TEST (Field, InitWorksAsExpected) {
  Field field;

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
