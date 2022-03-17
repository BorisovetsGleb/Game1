#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Throwable;
#include "Object.h"

class Player : public Object{
public:
    Player(int x, int y, int width, int height, int speed);
    void Move();
    Throwable* item;
    bool Alive = 1;
    int levelX = 0, levelY = 0;

private:
    bool CanUp();
    bool CanDown();
    bool CanLeft();
    bool CanRight();
};
extern vector<Player*> players;
#endif // PLAYER_H_INCLUDED
