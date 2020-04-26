#pragma once

#include "ResourceManager.h"
#include "Level.h"
#include "Player.h"
#include "Treasure.h"

class Game {
private:
  Level level;
  Player player;
  Treasure treasure;
  const ResourceManager& resources;
  void init();
  void intro();
  void victory();
  void checkLevelFinished();
  void draw();
  void action();
public:
  Game(const ResourceManager& resourceManager);
  void start();
  void play();
  bool isFinished();
  void end();
};