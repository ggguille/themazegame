#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
        Player();
        void callInput();
        void resetToSafePosition();
        int getX();
        int getY();
    protected:
        int x, lastX, y, lastY;
    private:
};

#endif // PLAYER_H
