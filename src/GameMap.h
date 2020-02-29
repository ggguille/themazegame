#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "MapCell.h"

class GameMap
{
private:
    /* data */
public:
    MapCell cells[15][10];
    GameMap(/* args */);
    void draw();
};


#endif // GAMEMAP_H