#include "GameMap.h"
#include <iostream>
#include <fstream>

using namespace std;

GameMap::GameMap(/* args */)
{
    this->playerCell = NULL;
    this->loadMap();
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
    this->playerCell = &(this->cells[playerY][playerX]);
    this->playerCell->id = 3;
}

void GameMap::loadMap()
{
    string line;
    ifstream file("res/map.txt");
    if (file.is_open())
    {

    }
    else
    {
        cout << "Fatal error: map file could not be loaded" << endl;
    }
    
}