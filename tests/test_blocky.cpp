#include <exception>
#include <cmath>

#include "gtest/gtest.h"

#include "component_factories.h"
#include "service_locator.h"

double square_root (const double x) {
  if (x < 0) {
    throw std::exception();
  }
  return sqrt(x);
}

TEST (SquareRootTest, PositiveNos) { 
  EXPECT_EQ (18.0, square_root (324.0));
  EXPECT_EQ (25.4, square_root (645.16));
  EXPECT_GT (0.001, 50.3321 - square_root (2533.310224));
}
 
TEST (SquareRootTest, ZeroAndNegativeNos) { 
  EXPECT_EQ (0.0, square_root (0.0));
  EXPECT_THROW(square_root (-22.0), std::exception);
}


TEST (AssertMainStructures, MainStructures) {
  ServiceLocator::provide(new ComponentFactory());
  //EXPECT_EQ(0, ServiceLocator::getComponentFactory()->getCreatorsMap()->size());
  //EXPECT_GT(0, ServiceLocator::getComponentFactory()->getCreatorsMap()->size());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
