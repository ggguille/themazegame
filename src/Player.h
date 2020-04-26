#pragma once

#include "Entity.h"
#include "EntityMovement.h"
#include "EntityLive.h"

class Player : public Entity, public EntityMovement, public EntityLive {
public:
  Player();
  void move(Map& map) override;
};