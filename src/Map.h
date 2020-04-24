#pragma once

#include <iostream>
#include <vector>
#include "Entity.h"

const char BLOCK_CHAR_ID = '1';

struct MapCell {
  char id;
  bool isBlocked() {
    return this->id == BLOCK_CHAR_ID;
  }
};

class Map {
private:
  MapCell cells[15][10];
public:
  Map();
  void build(const std::vector<std::string>& vMapStr);
  const char& getCellId(const int& x, const int& y);
  bool isCellAvailable(const int& x, const int& y);
  void draw(const Entity& entity);
};