#include "actor_feature.h"
#include "ai.h"
#include "openable.h"
#include "wearer.h"
#include "fighter.h"
#include "pickable.h"

namespace amarlon {

ActorFeature::ActorFeature()
  : _owner(nullptr)
{
}

ActorFeature* ActorFeature::create(Type featureType, Description *dsc)
{
  ActorFeature* feature = nullptr;

  if ( dsc)
  {
    switch( featureType )
    {
      case AI: feature = Ai::create(dsc); break;
      case OPENABLE: feature = Openable::create(dsc); break;
      case WEARER: feature = Wearer::create(dsc); break;
      case CONTAINER: feature = Container::create(dsc); break;
      case FIGHTER: feature = Fighter::create(dsc); break;
      case PICKABLE: feature = Pickable::create(dsc); break;
      default:;
    }
  }

  return feature;
}

ActorFeature::~ActorFeature()
{
}

void ActorFeature::setOwner(Actor *owner)
{
  _owner = owner;
}

}
