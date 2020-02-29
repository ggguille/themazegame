#include <iostream>
#include "src/Player.h"

using namespace std;

int main(int argc, char const *argv[])
{
    bool isGameOver = false;
    Player Hero;

    cout << "Game started" << endl;
    while (!isGameOver)
    {
        Hero.callInput();
    }
    return 0;
}
