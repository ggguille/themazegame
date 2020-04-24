#include <iostream>
#include "Entity.h"

Entity::Entity() {
  this->id = 'P';
  this->initialPosition();
}

void Entity::move() {
  this->lastY = this->y;
  this->lastX = this->x;
  std::cout << "Move: up (w), down (s), right (d) or left (a)" << std::endl;
  char userInput = ' ';
  std::cin >> userInput;
  switch (userInput)
  {
      case 'w':
          this->y -= 1;
          break;
      case 's':
          this->y += 1;
          break;
      case 'd':
          this->x += 1;
          break;
      case 'a':
          this->x -= 1;
          break;
  }
}

void Entity::resetToSafePosition() {
  this->y = this->lastY;
  this->x = this->lastX;
}

const int& Entity::getX() const {
  return this->x;
}

const int& Entity::getY() const {
  return this->y;
}

const char& Entity::getId() const {
  return this->id;
}

void Entity::initialPosition() {
  this->x = 1;
  this->y = 1;
  this->lastX = 1;
  this->lastY = 1;
}