#ifndef PIZZA_OWL_CPP_PROPERTY_RESTRICTION_HPP
#define PIZZA_OWL_CPP_PROPERTY_RESTRICTION_HPP

#include <memory>

namespace property_restriction
{

  /*
   * CLASS DEFINITION: property_restriction::Thing
   *
   */

  class Thing
  {
//    public:
//      const T& as<T>() const
//      {
//        return boost::dynamic_cast<const T>(*this);
//      }
  };

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
   * CLASS DEFINITION: property_restriction::SpatialThing
   *
   */

  class Pizza: public SpatialThing
  {
  };

  typedef typename std::shared_ptr<Pizza> PizzaPtr;
 
  class ObjectManipulation: public Thing
  {
    public:
      const SpatialThing& getObjActedOn() const
      {
        return objActedOn_;
      }
  
    protected:
      SpatialThing objActedOn_;
  };
  
//  class ServingPizza: public ObjectManipulation
//  {
//    public:
//      const Pizza& getObjActedOn() const
//      {
//        return ObjectManipulation::getObjActedOn().as<Pizza>();
//      }
//  
//      void setObjectActedOn(const Pizza& pizza)
//      {
//        objActedOn_ = pizza;
//      }
//  };

}

#endif 
