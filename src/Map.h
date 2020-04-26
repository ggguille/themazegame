#pragma once

#include <iostream>
#include <vector>
#include "Entity.h"

static const char BLOCK_CHAR_ID = '1';
const int MAP_ROWS = 15;
const int MAP_COLUMNS = 10;

struct MapCell {
  char id;
  bool isBlocked() {
    return this->id == BLOCK_CHAR_ID;
  }
};

class Map {
private:
  MapCell cells[15][10];
  bool validatePosition(const int& row, const int&column);
public:
  Map();
  void build(const std::vector<std::string>& vMapStr);
  const char getCellId(const int& row, const int& column);
  bool isCellAvailable(const int& row, const int& column);
  void draw(const std::vector<Entity>& vEntity);
  void clearEntities();
};