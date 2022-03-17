#ifndef FIREBALLENEMY_H_INCLUDED
#define FIREBALLENEMY_H_INCLUDED

//если будешь обращаться здесь к другим класса, то их нужно инициализировать(как в классе Player или Throwable)
class Throwable;
class Player;
class Level;
#include "Enemy.h"
//#include "main.cpp"
//extern Level->x = RoomX;
//отдельный враг
class FireBallEnemy : public Enemy{
public:
	FireBallEnemy(int x, int y, int w, int h, int RoomX, int RoomY);
	void FireEnemy();
private:
	void CanMove();//Can enemy move?
	void Move();//move, if can
	void CollisionWithPlayer();
	bool Alive = 1;//Is emeny alive?
	int x;
	int y;
	int w;
	int h;
	bool m1 = 0, m2 = 0, m3 = 0, m4 = 0;
	//Room InItRoom;//Room where enemy is in
	int RoomX, RoomY;
};

#endif // FIREBALLENEMY_H_INCLUDED
