#include "GameMap.h"
#include <iostream>
using namespace std;

GameMap::GameMap(/* args */)
{
    
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