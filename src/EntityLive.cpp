#include "EntityLive.h"

EntityLive::EntityLive(const int lives): lives(lives) {}

void EntityLive::substractLive() {
  lives--;
}

bool EntityLive::isAlive() {
  return lives > 0;
}