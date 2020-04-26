#pragma once

#include "Map.h"

class EntityMovement {
public:
  EntityMovement();
  virtual void move(Map& map) = 0;
};