#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <memory>
#include <libtcod.hpp>
#include "actor_type.h"
#include "data_gateways/actor_db.h"
#include "actor_features/actor_feature.h"
#include "actor_features/container.h"
#include "actor_features/pickable.h"
#include "actor_features/fighter.h"
#include "actor_features/ai/ai.h"
#include "actor_features/openable/openable.h"
#include "actor_features/wearer/wearer.h"
#include "amarlon_except.h"

namespace amarlon {

class Map;

class Actor
{
public:
  static ActorDB DB;
  static Actor* Player;
  static unsigned InstanceCounter;

  Actor(ActorType aId, int x = 0, int y = 0, Map* map = nullptr);
  ~Actor();

  Actor* clone();
  bool isEqual(Actor* rhs);

  void move(int dx, int dy);
  void morph(ActorType newType);
  void changeType(ActorType newType);

  bool isAlive() const;
  bool isFovOnly() const;
  bool isTransparent() const;
  bool blocks() const;
  int getTileRenderPriority() const;

  /**
   * Actor ID is not an unique instance id, but a type id from <actor_type.h>
   */
  ActorType getId() const;
  unsigned char getChar() const;
  TCODColor getColor() const;
  std::string getName() const;

  int getX() const;
  void setX(int getX);
  int getY() const;
  void setY(int getY);

  /**
   * @brief adds actor feature or overwrites existing one
   * @param feature to be inserted
   * @return overwriten feature if any, otherwise empty pointer
   */
  ActorFeaturePtr insertFeature(ActorFeature* feature);

  /**
   * @param feature type enum
   * @return actor feature as base class pointer
   */
  ActorFeature* getFeature(ActorFeature::Type afType) const;

  /**
   * @brief works similar to above getFeature, with the diference
   *        that it returns a pointer to derived class, not base
   *        example usage: getFeature<Pickable>()
   */
  template<typename T>
  T* getFeature() const;

  size_t getFeatureCount() const;

  template<typename T>
  bool hasFeature();

  unsigned getInstanceId() const;

private:
  ActorType _id;
  int _x, _y;
  Map* _map;
  unsigned _instanceId;

  FeatureMap _features;

};

typedef std::shared_ptr<Actor> ActorPtr;

// === IMPLEMENTATION === //

template<typename T>
T* Actor::getFeature() const
{
  auto it = _features.find( T::featureType );
  return it != _features.end() ? dynamic_cast<T*>(it->second.get()) : nullptr;
}

template<typename T>
bool Actor::hasFeature()
{
  return _features.find( T::featureType ) != _features.end();
}

}
#endif // ACTOR_H
