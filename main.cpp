#include <iostream>
#include "src/Player.h"
#include "src/MapCell.h"
#include "src/GameMap.h"

using namespace std;

int main(int argc, char const *argv[])
{
    bool isGameOver = false;
    Player hero;
    GameMap map;

    map.intro();

    cout << "Game started" << endl;
    while (!isGameOver)
    {
        if (!map.setPlayerCell(hero.getX(), hero.getY())) 
        {
            hero.resetToSafePosition();
        }
        map.draw();
        hero.callInput();
    }
    return 0;
}
