#include <cmath>
#include <exception>

#include "gtest/gtest.h"

/**
 * just to prove that everything works
 */

double square_root (const double x) {
  if (x < 0) {
    throw std::exception();
  }
  return sqrt(x);
}

TEST (SquareRootTest, PositiveNos) { 
  EXPECT_EQ (18.0, square_root (324.0));
  EXPECT_EQ (25.4, square_root (645.16));
  EXPECT_FLOAT_EQ (50.332, square_root (2533.310224));
}

TEST (SquareRootTest, ZeroAndNegativeNos) { 
  EXPECT_EQ (0.0, square_root (0.0));
  EXPECT_THROW (square_root (-22.0), std::exception);
  EXPECT_THROW (square_root (-0.000001), std::exception);
}
