#include <cstdlib>
#include <ctime>
#include "Enemy.h"

Enemy::Enemy(Position position): Entity('x'), EntityMovement(), EntityLive(1) {
  this->setPosition(position);
  this->count = 0;
  this->assignCurrentMovement();
}

void Enemy::move(Map& map) {
  Position newPosition = this->position;
  switch (this->current)
  {
      case 'w':
          newPosition.y -= 1;
          break;
      case 's':
          newPosition.y += 1;
          break;
      case 'd':
          newPosition.x += 1;
          break;
      case 'a':
          newPosition.x -= 1;
          break;
  }
  if (map.isCellAvailable(newPosition.y, newPosition.x)) {
    this->position = newPosition;
  } else {
    this->count++;
    this->assignCurrentMovement();
  }
}

void Enemy::assignCurrentMovement() {
  std::srand(std::time(nullptr));
  int randomValue = std::rand();
  const char* movements = "wasd";
  this->current = movements[randomValue % 4];
}