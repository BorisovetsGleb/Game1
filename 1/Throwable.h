#ifndef THROWABLE_H_INCLUDED
#define THROWABLE_H_INCLUDED

#include "Object.h"
class Player;
extern Player* player;
class Throwable : public Object{
public:
    Throwable(int x, int y, int width, int height, int acceleration, char throwableType);
    void Move();
    void CheckCollision();
private:
    bool isPicked;
    int acceleration;
    char throwableType;//texture of throwable. r - rock, s - stick
};

#endif // THROWABLE_H_INCLUDED
