#ifndef FIREBALLENEMY_H_INCLUDED
#define FIREBALLENEMY_H_INCLUDED

//���� ������ ���������� ����� � ������ ������, �� �� ����� ����������������(��� � ������ Player ��� Throwable)
class Throwable;
class Player;
class Level;
#include "Enemy.h"
//#include "main.cpp"
//extern Level->x = RoomX;
//��������� ����
class FireBallEnemy : public Enemy{
public:
	FireBallEnemy(int x, int y);
	void Logic();
private:
	void CanMove();//Can enemy move?
	void Move();//move, if can
	void CollisionWithPlayer();
	int x;
	int y;
	bool m1 = 0, m2 = 0, m3 = 0, m4 = 0;
	//Room InItRoom;//Room where enemy is in
};

#endif // FIREBALLENEMY_H_INCLUDED
