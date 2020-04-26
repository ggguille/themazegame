#pragma once

#include "Entity.h"
#include "EntityMovement.h"

const int NUMBER_OF_MOVEMENTS = 4;

class Enemy : public Entity, public EntityMovement {
public:
  Enemy(Position position);
  void move(Map& map) override;
private:
  const char* movements = "wasd";
  unsigned int count;
  char current;
  void assignCurrentMovement();
};