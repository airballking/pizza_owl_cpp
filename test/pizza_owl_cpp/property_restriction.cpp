#include <gtest/gtest.h>
#include <pizza_owl_cpp/property_restriction.hpp>

class PropertyRestrictionTest : public ::testing::Test
{
  protected:
    virtual void SetUp(){}

    virtual void TearDown(){}
};

TEST_F(PropertyRestrictionTest, CastDownSuccessfully)
{
  using namespace property_restriction;
  using namespace std;

  // initialize data structures
  PizzaPtr pizza = std::make_shared<Pizza>();
  ObjectManipulationPtr obj_manip = make_shared<ObjectManipulation>();
  obj_manip->setObjActedOn(pizza);

  // casting
  ServingPizzaPtr serve_pizza = 
    static_pointer_cast<ServingPizza>(obj_manip);

  // checking
  EXPECT_TRUE(obj_manip == serve_pizza);
  EXPECT_TRUE(obj_manip->getObjActedOn() == serve_pizza->getObjActedOn());
  EXPECT_TRUE(pizza == serve_pizza->getObjActedOn());
  EXPECT_TRUE(pizza == obj_manip->getObjActedOn());
}

TEST_F(PropertyRestrictionTest, CastUpSuccessfully)
{
  using namespace property_restriction;
  using namespace std;

  // initialize data structures
  PizzaPtr pizza = std::make_shared<Pizza>();
  ServingPizzaPtr serve_pizza = make_shared<ServingPizza>();
  serve_pizza->setObjActedOn(pizza);

  // casting
  ObjectManipulationPtr obj_manip = 
    static_pointer_cast<ObjectManipulation>(serve_pizza);

  // checking
  EXPECT_TRUE(obj_manip == serve_pizza);
  EXPECT_TRUE(obj_manip->getObjActedOn() == serve_pizza->getObjActedOn());
  EXPECT_TRUE(pizza == obj_manip->getObjActedOn());
  EXPECT_TRUE(pizza == serve_pizza->getObjActedOn());
}
