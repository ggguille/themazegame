#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "MapCell.h"

class GameMap
{
public:
    GameMap();
    MapCell* playerCell;
    MapCell cells[15][10];
    void draw();
    bool setPlayerCell(int playerX, int playerY);
protected:
    void loadMap();
};


#endif // GAMEMAP_H