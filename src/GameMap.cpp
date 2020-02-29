#include "GameMap.h"
#include <iostream>
using namespace std;

GameMap::GameMap(/* args */)
{
    this->playerCell = NULL;
}

void GameMap::draw()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << cells[i][j].id;
        }
        cout << endl;
    }
}

void GameMap::setPlayerCell(int playerX, int playerY)
{
    if (this->playerCell != NULL) 
    {
        this->playerCell->id = 0;
    }
    this->playerCell = &(this->cells[playerX][playerY]);
    this->playerCell->id = 3;
    //cout << "Player coords (" << playerX << ", " << playerY << ")" << endl;
}