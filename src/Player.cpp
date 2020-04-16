#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() 
{
    this->x = 1;
    this->y = 1;
}

void Player::callInput() 
{
    this->lastY = this->y;
    this->lastX = this->x;
    cout << "Move: up (w), down (s), right (d) or left (a)" << endl;
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

void Player::resetToSafePosition() 
{
    this->y = this->lastY;
    this->x = this->lastX;
}

int Player::getX()
{
    return this->x;
}

int Player::getY()
{
    return this->y;
}

void Player::init()
{
    this->x = 1;
    this->lastX = 1;
    this->y = 1;
    this->lastY = 1;
}