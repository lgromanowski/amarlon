#ifndef CONTAINER_H
#define CONTAINER_H

#include <memory>
#include <vector>
#include <list>
#include <string>
#include <functional>
#include "actor_feature.h"
#include "data_gateways/actor_descriptions.h"

namespace amarlon {

class Actor;

class Container : public ActorFeature
{
public:
  typedef std::list<Actor*>::iterator iterator;

  const static ActorFeature::Type featureType;

  iterator begin() { return _inventory.begin(); }
  iterator end() { return _inventory.end(); }

  Container(size_t slotCount);
  virtual ~Container();
  static Container* create(Description* dsc);

  virtual ActorFeature::Type getType() { return featureType; }

  virtual Container* clone();
  virtual bool isEqual(ActorFeature* rhs);

  bool add(Actor* actor);
  bool addFront(Actor* actor);
  bool remove(Actor* actor);
  std::vector<Actor *> content(std::function<bool(Actor *)>* filterFun = nullptr);
  size_t size() const;
  void performActionOnActors(std::function<void(Actor*)> fun);
  void sort(std::function<bool(Actor*, Actor*)> pred);

  size_t slotCount() const;
  void setSlotCount(const size_t &slotCount);

private:
  std::list<Actor*> _inventory;
  size_t _slotCount;
  bool _pushToFront;

  bool pushNewItem(Actor *actor);

};

typedef std::shared_ptr<Container> ContainerPtr;

}

#endif // CONTAINER_H
