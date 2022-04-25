#ifndef THROWABLE_H_INCLUDED
#define THROWABLE_H_INCLUDED

#include "Object.h"
#include "Animator.h"

class Player;
class Throwable : public Object, public Animator{
public:
    static vector<char> throwableTypes;
    Throwable(int x, int y, double acceleration, char throwableType);
    void Logic();//just for rendering right now
    void CheckCollision();//checks collision with player
    int speed;//current speed
    int rotationAngle;
    int throwAngle;//degrees
    bool isIdle;//is on one place (not flying)
    bool isPicked;//is on player
    double velocity;
    double velocityX;
    double velocityY;
    double accelerationX;//acceleration
    double accelerationY;
    double acceleration;
private:
    void Move();
    bool CanDown();
    bool CanUp();
    bool CanLeft();
    bool CanRight();
    char throwableType;//texture of throwable. r - rock, s - stick
};

#endif // THROWABLE_H_INCLUDED
