#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "Object.h"

class Enemy : public Object{
//��, ��� ����� ����� ��������� ���� ������
protected:
    bool alive;
    int hp;
    int damage;
};

#endif // ENEMY_H_INCLUDED
