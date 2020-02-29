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
        this->playerCell->id = ' ';
    }
    this->playerCell = &(this->cells[playerY][playerX]);
    this->playerCell->id = 'P';
}

void GameMap::loadMap()
{
    string line;
    ifstream file("res/map.txt");
    if (file.is_open())
    {
        int lineIndex = 0;
        int charIndex;
        while (getline(file, line))
        {
            for (charIndex = 0; charIndex < 10; charIndex++) 
            {
                if (line[charIndex] == '0')
                {
                    this->cells[lineIndex][charIndex].id = ' ';
                }
                else 
                {
                    this->cells[lineIndex][charIndex].id = line[charIndex];
                }
            }
            lineIndex++;
        }
    }
    else
    {
        cout << "Fatal error: map file could not be loaded" << endl;
    }
    
}