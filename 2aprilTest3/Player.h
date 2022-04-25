#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Throwable;
#include "Animator.h"
#include "Object.h"

class Player : public Object, public Animator{
public:
    Player(int x, int y, int width, int height, int speed);
    Player(int x, int y, int width, int height);
    enum Animations{
        idle = 0,
        death = 19,
    };
    enum AnimationsFrames{
        idleF = 2,
        deathF = 1,
    };
    void Logic();
    Throwable* item;
    bool onLevel;
    bool alive;
    int speed;
private:
    SDL_Rect* srcRect;
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
