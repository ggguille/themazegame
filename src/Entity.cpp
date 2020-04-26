#include <iostream>
#include "Entity.h"

Entity::Entity(const char representation): id(representation) {}

const Position& Entity::getPosition() {
  return this->position;
}

void Entity::setPosition(const Position position) {
  this->position = position;
}

const char& Entity::getId() const {
  return this->id;
}