#include <iostream>
#include "ResourceManager.h"
#include "Game.h"

int main(int argc, char const *argv[]) {
  std::cout << "\033[2J\033[H";
  ResourceManager resources;
  Game game(resources);
  game.start();
  while (!game.isFinished()) {
    game.play();
    //std::cout << "\033[2J\033[H";
  }
  game.end();
}
