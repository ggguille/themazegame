#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <iostream>
#include "MapCell.h"

class GameMap
{
public:
    GameMap();
    MapCell* playerCell;
    MapCell cells[15][10];
    void intro();
    void victory();
    void draw();
    bool setPlayerCell(int playerX, int playerY);
    bool isFinish();
    void loadMap(const std::string& mapLevel);
protected:
    bool isGameOver;
};


#endif // GAMEMAP_H