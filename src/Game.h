#pragma once

#include "ResourceManager.h"
#include "Map.h"
#include "Entity.h"

class Game {
private:
  int currentLevel;
  Entity player;
  const ResourceManager& resources;
  Map map;
  void intro();
  void victory();
  void checkLevelFinished();
  void loadMap();
public:
  Game(const ResourceManager& resourceManager);
  void start();
  void play();
  bool isFinished();
  void end();
};