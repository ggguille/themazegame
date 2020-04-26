#include <iostream>
#include "Player.h"

Player::Player(): Entity('P'), EntityMovement() {}

void Player::move(Map& map) { 
  Position newPosition = this->position;
  std::cout << "Move: up (w), down (s), right (d) or left (a)" << std::endl;
  char userInput = ' ';
  std::cin >> userInput;
  switch (userInput)
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
  }
}