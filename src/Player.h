#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
        Player();
        //virtual ~Player();
        void callInput();
        int getX();
        int getY();
    protected:
        int x, y;
    private:
};

#endif // PLAYER_H
