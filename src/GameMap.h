#ifndef GAMEMAP_H
#define GAMEMAP_H

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
protected:
    bool isGameOver;
    void loadMap();
};


#endif // GAMEMAP_H