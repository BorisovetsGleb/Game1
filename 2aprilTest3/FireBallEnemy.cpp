#include "FireBallEnemy.h"
#include "Extern.h"
#include "Level.h"//может быть ещё что-то придётся подключить
//#include "main.cpp"

FireBallEnemy::FireBallEnemy(int x, int y) : Enemy(x, y){
	this->x = x;
	this->y = y;
	alive = 1;
	rectanglePointer->w = 50;
	rectanglePointer->h = 50;
	texturePointer = textures[18];
}

void FireBallEnemy::CanMove(){
	if (abs(players[0]->x - x) < 20 && players[0]->y < y){
		//y = y - 20;
		m1 = 1;
	}
	if (abs(players[0]->x - x) < 20 && players[0]->y > y){
		//y = y + 20;
		m2 = 1;
	}
	if (abs(players[0]->y - y) < 20 && players[0]->x < x){
		//x = x - 20;
		m3 = 1;
	}
	if (abs(players[0]->y - y) < 20 && players[0]->x > x){
		//x = x + 20;
		m4 = 1;
	}
}

void FireBallEnemy::Move(){
	if (m1) { y = y - 20; }
	else if (m2) { y = y + 20; }
	else if (m3) { x = x - 20; }
	else if (m4) { x = x + 20; }
}

void FireBallEnemy::CollisionWithPlayer(){
	if (abs(players[0]->x - x) < 50 && abs(players[0]->y - y) < 50){
	    Level::numberOfEnemies--;
		cout << Level::numberOfEnemies;
		alive = 0;
		players[0]->alive = 0;
		players[0]->ChangeSequence(19, 1);
	}
}

void FireBallEnemy::Logic(){
    if(alive){
        if (x < 0 || y < 0 || x > 2000 || y > 2000){
            alive = 0;
            Level::numberOfEnemies--;
            cout << Level::numberOfEnemies;
        }
        CanMove();
        Move();
        CollisionWithPlayer();
        rectanglePointer->x = x;
        rectanglePointer->y = y;
        SDL_RenderCopy(renderer, texturePointer, NULL, rectanglePointer);
    }
}
