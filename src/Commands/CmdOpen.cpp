#include "CmdOpen.h"
#include <iostream>
#include "Utils/Utils.h"
#include <Utils/ItemPicker.h>
#include <algorithm>
#include "CmdPick.h"
#include "World/Map.h"
#include "Engine.h"

CmdOpen::CmdOpen()
{
}

bool CmdOpen::accept(TCOD_key_t &key)
{
  return ( key.vk == TCODK_CHAR && key.c == 'o' );
}

void CmdOpen::execute(Engine *engine, Actor *executor)
{
  Map* map = engine->currentMap();
  int x = executor->getX();
  int y = executor->getY();

  int dx(0), dy(0);

  _dSelector.select(dx, dy);

  Actor* target = map->getFirstActor(x+dx, y+dy);

  if ( target && target->afOpenable() )
  {
    if ( target->afOpenable()->open(executor) )
    {
      map->updateActorCell(target);
    }
  }
}
