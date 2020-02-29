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
            this->y -= 1;
            break;
        case 's':
            this->y += 1;
            break;
        case 'd':
            this->x += 1;
            break;
        case 'a':
            this->x -= 1;
            break;
    }
}

int Player::getX()
{
    return this->x;
}

int Player::getY()
{
    return this->y;
}