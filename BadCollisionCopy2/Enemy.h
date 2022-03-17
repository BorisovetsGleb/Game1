#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "Object.h"

class Enemy : public Object{
//всё, что можно будет присвоить всем врагам
private:
    int hp;
    int damage;
};

#endif // ENEMY_H_INCLUDED
