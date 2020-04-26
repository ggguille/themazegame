#pragma once

class EntityLive {
public:
  EntityLive(const int lives);
  void substractLive();
  bool isAlive();
private:
  int lives;
};