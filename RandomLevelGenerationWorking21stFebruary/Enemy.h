#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "Object.h"

class Enemy : public Object{
//��, ��� ����� ����� ��������� ���� ������
private:
    int hp;
    int damage;
};

#endif // ENEMY_H_INCLUDED
