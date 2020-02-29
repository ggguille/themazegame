#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() 
{
    this->x = 1;
    this->y = 1;
}
/*
Player::~Player()
{

}
*/
void Player::callInput() 
{
    char userInput = ' ';
    cin >> userInput;
    switch (userInput)
    {
        case 'w':
            this->y += 1;
            cout << "Player moves up" << endl;
            break;
        case 's':
            this->y -= 1;
            cout << "Player moves down" << endl;
            break;
        case 'd':
            this->x += 1;
            cout << "Player moves right" << endl;
            break;
        case 'a':
            this->x -= 1;
            cout << "Player moves left" << endl;
            break;
    }
    cout << "Player is in coords (" << this->x << ", " << this->y << ")" << endl;
}