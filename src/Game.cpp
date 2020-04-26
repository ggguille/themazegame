#include <iostream>
#include <vector>

#include "Game.h"

static const int MAX_LEVELS = 3;

Game::Game(const ResourceManager& resourceManager): 
  resources(resourceManager), level(Level(resourceManager, MAX_LEVELS)) {
  this->init();
}

void Game::init() {
  this->player.setPosition(level.initialPlayerPosition());
  this->treasure.setPosition(level.getTreasurePosition());
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
  if (player.getPosition() == treasure.getPosition()) {
    level.levelUp();
    if (!isFinished()) {
      init();
    }
  }
}

bool Game::isFinished() {
  return level.current() > MAX_LEVELS;
}

void Game::start() {
  intro();
  std::cin.get();
}

void Game::draw() {
  std::vector<Entity> entities;
  entities.push_back(treasure);
  entities.push_back(player);
  level.getMap().draw(entities);
}

void Game::action() {
  player.move(level.getMap());
}

void Game::play() {
  draw();
  action();
  checkLevelFinished();
}

void Game::end() {
  victory();
}