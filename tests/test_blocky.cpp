#include "gtest/gtest.h"

#include "component_factories.h"
#include "service_locator.h"


TEST (ComponentFactoryInit, InitWorksAsExpected) {
  ServiceLocator::provide(new ComponentFactory());
  EXPECT_EQ(ServiceLocator::getComponentFactory()->getCreatorsMap()->size(), 0);
  ServiceLocator::getComponentFactory()->init();
  EXPECT_GE(ServiceLocator::getComponentFactory()->getCreatorsMap()->size(), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
