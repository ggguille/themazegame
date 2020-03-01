#include "GameMap.h"
#include "MapCell.h"
#include <iostream>
#include <fstream>

using namespace std;

GameMap::GameMap(/* args */)
{
    this->playerCell = NULL;
    this->loadMap();
}

void GameMap::intro()
{
    string line;
    ifstream file("res/intro.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
        cin >> line;
    }
    else
    {
        cout << "Fatal error: intro could not be loaded" << endl;
    }
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

bool GameMap::setPlayerCell(int playerX, int playerY)
{
    MapCell* cell = &(this->cells[playerY][playerX]);
    if (cell->isBlocked())
    {
        return false;
    }

    if (this->playerCell != NULL) 
    {
        this->playerCell->id = ' ';
    }
    this->playerCell = cell;
    this->playerCell->id = 'P';
    return true;
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