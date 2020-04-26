#pragma once

#include "Entity.h"
#include "EntityMovement.h"
#include "Map.h"

class Player : public Entity, public EntityMovement {
public:
  Player();
  void move(Map& map) override;
};