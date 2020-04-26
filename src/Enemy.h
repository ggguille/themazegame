#pragma once

#include "Entity.h"
#include "EntityMovement.h"
#include "EntityLive.h"

class Enemy : public Entity, public EntityMovement, public EntityLive {
public:
  Enemy(Position position);
  void move(Map& map) override;
private:
  unsigned int count;
  char current;
  void assignCurrentMovement();
};