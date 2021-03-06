#include "utils.h"
#include <actor.h>
#include <pickable.h>

namespace amarlon {

std::string getItemNameAndAmount(Actor* a)
{
  std::string value = a->getName();
  if ( Pickable* pickable = a->getFeature<Pickable>() )
  {
    if ( pickable->getAmount() > 1 )
    {
      value += " (" + std::to_string(pickable->getAmount()) + ")";
    }
  }
  return value;
}

}
