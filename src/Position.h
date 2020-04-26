#pragma once

struct Position {
  int x;
  int y;

  Position(): x(0), y(0) {}
  Position(const int x, const int y): x(x), y(y) {}

  bool operator==(const Position& comparator) const {
    return x == comparator.x && y == comparator.y;
  }
};