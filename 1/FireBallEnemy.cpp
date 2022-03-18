#include "FireBallEnemy.h"
#include "Extern.h"
#include "Level.h"//����� ���� ��� ���-�� ������� ����������
//#include "main.cpp"

FireBallEnemy::FireBallEnemy(int x, int y, int w, int h, int RoomX, int RoomY)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	rectanglePointer = new SDL_Rect;
	rectanglePointer->w = w;
	rectanglePointer->h = h;
	texturePointer = textures[15];
}

void FireBallEnemy::CanMove()
{
	if (abs(players[0]->x - x) < 20 && players[0]->y < y)
	{
		//y = y - 20;
		m1 = 1;
	}
	if (abs(players[0]->x - x) < 20 && players[0]->y > y)
	{
		//y = y + 20;
		m2 = 1;
	}
	if (abs(players[0]->y - y) < 20 && players[0]->x < x)
	{
		//x = x - 20;
		m3 = 1;
	}
	if (abs(players[0]->y - y) < 20 && players[0]->x > x)
	{
		//x = x + 20;
		m4 = 1;
	}
}

void FireBallEnemy::Move()
{
	if (m1) { y = y - 20; }
	else if (m2) { y = y + 20; }
	else if (m3) { x = x - 20; }
	else if (m4) { x = x + 20; }
}

void FireBallEnemy::CollisionWithPlayer()
{
	if (abs(players[0]->x - x) < 50 && abs(players[0]->y - y) < 50)
	{
		Alive = 0;
		players[0]->Alive = 0;
	}
}

void FireBallEnemy::FireEnemy()
{
	if (Alive && RoomX == players[0]->levelX && RoomY == players[0]->levelY)
	{
		if (x < 0 || y < 0 || x > 2000 || y > 2000) { Alive = 0; }
		CanMove();
		Move();
		CollisionWithPlayer();
		rectanglePointer->x = x;
		rectanglePointer->y = y;
		SDL_RenderCopy(renderer, texturePointer, NULL, rectanglePointer);
	}
}
