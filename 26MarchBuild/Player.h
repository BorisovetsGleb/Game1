#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Throwable;
#include "Object.h"

class Player : public Object{
public:
    Player(int x, int y, int width, int height, int speed);
    void Logic();
    Throwable* item;
    bool onLevel;
    bool alive;
private:
    void Move();
    void OnExit();//change room when trying to leave it
    void Throw();
    void CheckTile();
    bool CanUp();
    bool CanDown();
    bool CanLeft();
    bool CanRight();
    bool throwStarted;
    int onTile;//number of tile the player is on
};
extern vector<Player*> players;
#endif // PLAYER_H_INCLUDED
