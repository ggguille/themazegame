#pragma once

#include <vector>
#include "ResourceManager.h"
#include "Position.h"
#include "Map.h"

class Level {
public:
  Level(const ResourceManager& resourceManager, const int maxLevels);
  void levelUp();
  const Position initialPlayerPosition();
  const Position getTreasurePosition();
  const std::vector<Position> getEnemiePositions();
  Map& getMap();
  const int& current();
private:
  const int maxLevels;
  int id; 
  Position playerPosition;
  Position treasurePosition;
  std::vector<Position> vEnemyPosition;
  Map map;
  const ResourceManager& resources; 
  void load();
};