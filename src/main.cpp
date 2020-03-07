#include <iostream>
#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Player hero;
    GameMap map;

    map.intro();
    cout << "Game started" << endl;
    while (!map.isFinish())
    {
        if (!map.setPlayerCell(hero.getX(), hero.getY())) 
        {
            hero.resetToSafePosition();
        }

        if (!map.isFinish()) {
            map.draw();
            hero.callInput();
        }
    }
    return 0;
}
