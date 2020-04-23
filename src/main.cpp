#include <iostream>
#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"

using namespace std;

bool endGame(int level) {
    return level > 3;
}

int main(int argc, char const *argv[])
{
    Player hero;
    GameMap map;
    int level = 1;

    map.intro();
    cout << "Game started" << endl;
    cin.get(); 
    map.loadMap(std::to_string(level));
    map.setPlayerCell(hero.getX(), hero.getY());
    while (!endGame(level))
    {
        map.draw();
        hero.callInput();

        if (!map.setPlayerCell(hero.getX(), hero.getY())) 
        {
            hero.resetToSafePosition();
        }

        if (map.isFinish()) {
            level++;
            if (!endGame(level)) {
                map.loadMap(std::to_string(level));
                hero.init();
                map.setPlayerCell(hero.getX(), hero.getY());
            }
        }
    }
    map.victory();
    return 0;
}
