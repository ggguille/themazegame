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
  if (this->enemies.size() > 0) {
    this->enemies.clear();
  }
  std::vector<Position> enemyPositions = level.getEnemiePositions();
  for (Position& position : enemyPositions) {
    this->enemies.push_back(Enemy(position));
  }
}

void Game::intro() {
  std::vector<string> text = resources.fetch("intro.txt");
  for (std::string& str : text) {
    std::cout << str << std::endl;
  }
}

void Game::victory() {
  vector<string> text = resources.fetch("victory.txt");
  for (std::string& str : text) {
    std::cout << str << std::endl;
  }
}

void Game::gameover() {
  vector<string> text = resources.fetch("gameover.txt");
  for (std::string& str : text) {
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
  return level.current() > MAX_LEVELS || !player.isAlive();
}

void Game::start() {
  intro();
  std::cin.get();
}

void Game::draw() {
  std::vector<Entity> entities;
  entities.push_back(treasure);
  entities.push_back(player);
  for (Enemy& enemy : enemies) {
    if (enemy.isAlive()) {
      entities.push_back(enemy);
    }
  }
  level.getMap().draw(entities);
}

void Game::action() {
  player.move(level.getMap());
  for (Enemy& enemy : enemies) {
    enemy.move(level.getMap());
    if (enemy.isAlive() && player.getPosition() == enemy.getPosition()) {
      player.substractLive();
      enemy.substractLive();
    }
  }
}

void Game::play() {
  draw();
  action();
  checkLevelFinished();
}

void Game::end() {
  if (player.isAlive()) {
    victory();
  } else {
    gameover();
  }
}