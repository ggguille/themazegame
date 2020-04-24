#include <iostream>
#include <vector>

#include "Game.h"

Game::Game(const ResourceManager& resourceManager): resources(resourceManager) {
  this->currentLevel = 1;
}

void Game::intro() {
  std::vector<string> vIntro = resources.fetch("intro.txt");
  for (std::string str : vIntro) {
    std::cout << str << std::endl;
  }
}

void Game::victory() {
  vector<string> vVictory = resources.fetch("victory.txt");
  for (std::string str : vVictory) {
    std::cout << str << std::endl;
  }
}

void Game::checkLevelFinished() {
  const char cellId = map.getCellId(player.getX(), player.getY());
  if (cellId == '$') {
    currentLevel++;
    if (!isFinished()) {
      loadMap();
      player.initialPosition();
    }
  }
}

bool Game::isFinished() {
  return currentLevel > 3;
}

void Game::loadMap() {
  std::vector<std::string> vMap = resources.fetch("maps/" + std::to_string(this->currentLevel) + ".txt");
  map.build(vMap);
}

void Game::start() {
  intro();
  std::cin.get(); 
  loadMap();
}

void Game::play() {
  map.draw(player);
  player.move();
  if (map.isCellAvailable(player.getX(), player.getY())) {
    checkLevelFinished();
  } else {
    player.resetToSafePosition();
  }
}

void Game::end() {
  victory();
}