#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "Object.h"
#include "Animator.h"

class Enemy : public Object, public Animator{
//всё, что можно будет присвоить всем врагам
public:
    Enemy(int x, int y);
protected:
    bool alive;
    int hp;
    int damage;
};

#endif // ENEMY_H_INCLUDED
