#ifndef PIZZA_OWL_CPP_PROPERTY_RESTRICTION_HPP
#define PIZZA_OWL_CPP_PROPERTY_RESTRICTION_HPP

#include <memory>

namespace property_restriction
{

  /*
   * CLASS DEFINITION: property_restriction::Thing
   *
   */

  class Thing {};

  typedef typename std::shared_ptr<Thing> ThingPtr;

  /*
   * CLASS DEFINITION: property_restriction::SpatialThing
   *
   */

  class SpatialThing: public Thing
  {
  };

  typedef typename std::shared_ptr<SpatialThing> SpatialThingPtr;

  /*
   * CLASS DEFINITION: property_restriction::Pizza
   *
   */

  class Pizza: public SpatialThing
  {
  };

  typedef typename std::shared_ptr<Pizza> PizzaPtr;

  /*
   * CLASS DEFINITION: property_restriction::ObjectManipulation
   *
   */

  class ObjectManipulation: public Thing
  {
    public:
      SpatialThingPtr getObjActedOn() const
      {
        return objActedOn_;
      }

      void setObjActedOn(SpatialThingPtr objActedOn)
      {
        objActedOn_ = objActedOn;
      }
  
 
    protected:
      SpatialThingPtr objActedOn_;
  };

  typedef typename std::shared_ptr<ObjectManipulation> ObjectManipulationPtr;

  /*
   * CLASS DEFINITION: property_restriction::ServingPizza
   *
   */

  class ServingPizza: public ObjectManipulation
  {
    public:
      PizzaPtr getObjActedOn() const
      {
        return std::static_pointer_cast<Pizza>(objActedOn_);
      }
  
      void setObjectActedOn(PizzaPtr objActedOn)
      {
        objActedOn_ = objActedOn;
      }
  };

  typedef typename std::shared_ptr<ServingPizza> ServingPizzaPtr;
}

#endif 
