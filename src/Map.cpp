#include "Map.h"

Map::Map() {}

bool Map::validatePosition(const int& row, const int&column) {
  return (row >= 0 && row < MAP_ROWS && column >= 0 && column < MAP_COLUMNS);
}

void Map::build(const std::vector<std::string>& vMapStr) {
  int charIndex;
  std::string line;
  for(int lineIndex = 0; lineIndex < vMapStr.size(); lineIndex++) {
      line = vMapStr.at(lineIndex);
      for (charIndex = 0; charIndex < 10; charIndex++) {
          if (line[charIndex] == '0') {
              this->cells[lineIndex][charIndex].id = ' ';
          } else {
              this->cells[lineIndex][charIndex].id = line[charIndex];
          }
      }
  }
}

void Map::clearEntities() {
  for (int row = 0; row < 15; row++) {
      for (int column = 0; column < 10; column++) {
        if (cells[row][column].id != ' ' && cells[row][column].id != '1') {
          cells[row][column].id = ' ';
        }
      }
  }
}

const char Map::getCellId(const int& row, const int& column) {
  if (validatePosition(row, column)) {
    return cells[row][column].id;
  }
  return '0';
}

bool Map::isCellAvailable(const int& row, const int& column) {
  return validatePosition(row, column) && !this->cells[row][column].isBlocked();
}

void Map::draw(const std::vector<Entity>& vEntity) { 
  char map[15][10];
  for (int row = 0; row < 15; row++) {
      for (int column = 0; column < 10; column++) {
        map[row][column] = cells[row][column].id;
      }
  }
  for (Entity entity : vEntity) {
    if (validatePosition(entity.getPosition().y, entity.getPosition().x)) {
      map[entity.getPosition().y][entity.getPosition().x] = entity.getId();
    }
  }

  for (int i = 0; i < 15; i++) {
      for (int j = 0; j < 10; j++) {
          std::cout << map[i][j];
      }
      std::cout << std::endl;
  }
}