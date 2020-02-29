#include "MapCell.h"

MapCell::MapCell(/* args */)
{
    this->id = 0;
}

bool MapCell::isBlocked()
{
    return this->id == '1';
}