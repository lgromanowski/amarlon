#ifndef OPENABLEDOOR_H
#define OPENABLEDOOR_H

#include "Openable.h"

class OpenableDoor : public Openable
{
public:
  OpenableDoor();

  virtual bool open(Actor* executor);
  virtual bool close(Actor* executor);
  virtual ActorFeature* clone();

  virtual bool lock();

};

#endif // OPENABLEDOOR_H
