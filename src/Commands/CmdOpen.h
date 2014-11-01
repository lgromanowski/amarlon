#ifndef CMDOPEN_H
#define CMDOPEN_H

#include "Command.h"
#include "Utils/DirectionSelector.h"

namespace amarlon {

class CmdOpen : public Command
{
public:
  CmdOpen(Engine* engine);
  virtual bool accept(TCOD_key_t &key);
  virtual void execute(Actor* executor);

private:
  DirectionSelector _dSelector;

};

}

#endif // CMDOPEN_H
