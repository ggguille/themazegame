#include "Map.h"

Map::Map() {}

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

const char& Map::getCellId(const int& x, const int& y) {
  return this->cells[y][x].id;
}

bool Map::isCellAvailable(const int& x, const int& y) {
  return !this->cells[y][x].isBlocked();
}

void Map::draw(const Entity& entity) {
  char map[15][10];
  for (int i = 0; i < 15; i++) {
      for (int j = 0; j < 10; j++) {
          map[i][j] = cells[i][j].id;
      }
  }

  map[entity.getY()][entity.getX()] = entity.getId();

  for (int i = 0; i < 15; i++) {
      for (int j = 0; j < 10; j++) {
          std::cout << map[i][j];
      }
      std::cout << std::endl;
  }
}