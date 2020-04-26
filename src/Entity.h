#pragma once

#include "Position.h"

class Entity {
public:
    Entity(const char representation);
    const Position& getPosition();
    void setPosition(const Position position); 
    const char& getId() const;
protected:
    const char id;
    Position position;
};