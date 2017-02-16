#include <gtest/gtest.h>
#include <pizza_owl_cpp/poc.hpp>

class PropertyRestrictionTest : public ::testing::Test
{
  protected:
    virtual void SetUp(){}

    virtual void TearDown(){}
};

TEST_F(PropertyRestrictionTest, MakePizza)
{
  auto pizza = std::make_shared<property_restriction::Pizza>();
}
