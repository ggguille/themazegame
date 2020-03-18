#include <iostream>
#include <fstream>
#include <vector>

#include "GameMap.h"
#include "MapCell.h"
#include "ResourceManager.h"

using namespace std;

GameMap::GameMap(/* args */)
{
    this->isGameOver = false;
    this->playerCell = NULL;
    this->loadMap();
}

void GameMap::intro()
{
    ResourceManager res;
    vector<string> vIntro = res.fetch("intro.txt");
    for(vector<string>::iterator it = vIntro.begin(); it != vIntro.end(); it++) {
        cout << *it << endl;
    }
}

void GameMap::victory()
{
    ResourceManager res;
    vector<string> vIntro = res.fetch("victory.txt");
    for(vector<string>::iterator it = vIntro.begin(); it != vIntro.end(); it++) {
        cout << *it << endl;
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

    if (cell->id == '$')
    {
        this->isGameOver = true;
        this->victory();
        return true;
    }

    if (this->playerCell != NULL) 
    {
        this->playerCell->id = ' ';
    }
    this->playerCell = cell;
    this->playerCell->id = 'P';
    return true;
}

bool GameMap::isFinish()
{
    return this->isGameOver;
}

void GameMap::loadMap()
{
    ResourceManager res;
    vector<string> vIntro = res.fetch("map.txt");
    int charIndex;
    string line;
    for(int lineIndex = 0; lineIndex < vIntro.size(); lineIndex++) {
        line = vIntro.at(lineIndex);
        for (charIndex = 0; charIndex < 10; charIndex++) {
            if (line[charIndex] == '0') {
                this->cells[lineIndex][charIndex].id = ' ';
            } else {
                this->cells[lineIndex][charIndex].id = line[charIndex];
            }
        }
    }
}