#include "Level.h"

Level::Level(const ResourceManager& resourceManager, const int maxLevels): 
  resources(resourceManager), maxLevels(maxLevels) {
  this->id = 1;
  this->load();
}

void Level::load() {
  this->vEnemyPosition.clear();
  std::vector<std::string> vMapStr = resources.fetch("maps/" + std::to_string(this->id) + ".txt");
  this->map.build(vMapStr);
  for (int row = 0; row < MAP_ROWS; row++) {
    for (int column = 0; column < MAP_COLUMNS; column++) {
      switch (this->map.getCellId(row, column)) {
        case 'P':
          this->playerPosition.x = column;
          this->playerPosition.y = row;
          break;
        case '$':
          this->treasurePosition.x = column;
          this->treasurePosition.y = row;
          break;
        case 'x':
          this->vEnemyPosition.push_back(Position(column, row));
          break;
      }
    } 
  }
  this->map.clearEntities();
}

const int& Level::current() {
  return this->id;
}

void Level::levelUp() {
  this->id++;
  if (this->id <= this->maxLevels) {
    this->load();
  }
}

const Position Level::initialPlayerPosition() {
  return this->playerPosition;
}

const Position Level::getTreasurePosition() {
  return this->treasurePosition;
}
const std::vector<Position> Level::getEnemiePositions() {
  return this->vEnemyPosition;
}
Map& Level::getMap() { 
  return this->map;
}
