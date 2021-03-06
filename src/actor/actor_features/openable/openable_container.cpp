#include "openable_container.h"
#include "actor/actor.h"
#include "engine.h"
#include "utils/messenger.h"
#include "utils/utils.h"
#include "gui/window/pick_up_window.h"
#include "gui/message_box.h"

namespace amarlon {

OpenableContainer::OpenableContainer()
{
}

bool OpenableContainer::open(Actor *executor)
{
  bool r = false;

  if ( _owner->hasFeature<Container>() )
  {
    auto afterPickupAction =
    [&](const std::string& item, int amount)
    {
      Messenger::message()->actorPicked(executor->getName(), item, amount, _owner->getName());
    };

    auto inventoryFullAction =
    [&](const std::string& item)
    {
      gui::msgBox("Cannot pickup "+item+" from "+tolowers(_owner->getName())+":\nInventory is full!",
                  gui::MsgType::Error);
    };

    Engine::instance().windowManager()
                      .getWindow<gui::PickUpWindow>()
                      .setPicker(executor)
                      .setContainer(_owner->getFeature<Container>())
                      .setFilterFunction( [](Actor* a){ return a->getFeature<Pickable>();} )
                      .setAfterPickupAction( afterPickupAction )
                      .setInventoryFullAction( inventoryFullAction )
                      .show();

    r = true;
  }

  return r;
}

bool OpenableContainer::close(Actor*)
{
  return true;
}

ActorFeature *OpenableContainer::clone()
{
  OpenableContainer* cloned = new OpenableContainer;
  cloned->setLockId( getLockId() );
  isLocked() ? cloned->lock() : cloned->unlock();

  return cloned;
}

bool OpenableContainer::isEqual(ActorFeature *rhs)
{
  bool equal = false;
  OpenableContainer* crhs = dynamic_cast<OpenableContainer*>(rhs);

  if (crhs)
  {
    equal = (_lockId == crhs->_lockId);
  }

  return equal;
}

}
