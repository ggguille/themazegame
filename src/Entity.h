#pragma once

class Entity {
public:
    Entity();
    void move();
    void resetToSafePosition();
    const int& getX() const;
    const int& getY() const;
    const char& getId() const;
    void initialPosition();
protected:
    char id;
    int x, lastX, y, lastY;
};