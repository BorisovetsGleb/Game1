#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include "F1.h"
#define WINDOW_WIDHT = 600

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int Speed = 10;
int Level = 1;

bool Alive = 1;
bool EnemyAlive = 1;


SDL_Window* win = NULL;
SDL_Surface* scr = NULL;
SDL_Surface* flower = NULL;
SDL_Surface* level = NULL;
SDL_Surface* s1 = NULL;

//enemy
SDL_Surface* enemy = NULL;


//Level 1; перевернут на бок (/*не знаю, как исправить*/ так и должно быть)
//ID: 1-wall up and down, 2-wall left and right, 0-ground, 3, 4, 5, 6-wall-ygol
vector<vector<int>>Level1 = {
		{3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 3, 7, 7, 7, 4, 8, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 5, 7, 7, 7, 6, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6}
};

vector <const char*> ground = { "Ground1.png", "Ground2.png", "Ground3.png", "Ground1.png", "Ground4.png", "Ground5.png", "Ground1.png"};

bool init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Can't init video: " << SDL_GetError() << std::endl;
		return false;
	}

	int flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags) & flags)) {
		std::cout << "Can't init image: " << IMG_GetError() << std::endl;
		return false;
	}

	win = SDL_CreateWindow("GG_Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_MAXIMIZED);
	if (win == NULL) {
		std::cout << "Can't create window: " << SDL_GetError() << std::endl;
		return false;
	}

	scr = SDL_GetWindowSurface(win);

	return true;
}

bool load() {
	flower = IMG_Load("Character1.png");
	if (flower == NULL) {
		std::cout << "Can't load: " << IMG_GetError() << std::endl;
	}

	flower = SDL_ConvertSurface(flower, scr->format, NULL);
	if (flower == NULL) {
		std::cout << "Can't convert: " << SDL_GetError() << std::endl;
	}
	return true;
}

void quit() {
	SDL_FreeSurface(flower);

	SDL_FreeSurface(scr);
	SDL_DestroyWindow(win);

	SDL_Quit();
	IMG_Quit();
}

vector <SDL_Surface*> sprites = {
	IMG_Load(ground[rand() % 7]),
	IMG_Load("Wall1.png"),
	IMG_Load("WallYgol1.png"),
	IMG_Load("WallYgol4.png"),
	IMG_Load("WallYgol2.png"),
	IMG_Load("WallYgol3.png"),
	IMG_Load("Wall4.png"),
	IMG_Load("GroundAttack.png"),
	IMG_Load("EnemySpawner.png")
};

void LoadLevel(int levelID)
{
	SDL_Rect TilePlace;
	TilePlace.w = 55;
	TilePlace.h = 55;
	if (levelID == 1)
	{
		for (int x1 = 0; x1 < 30; x1++)
		{
			for (int y1 = 0; y1 < 20; y1++)
			{
				TilePlace.x = x1 * 50 + 25;
				TilePlace.y = y1 * 50 + 25;		
				SDL_BlitScaled(sprites[Level1[x1][y1] - 1], NULL, scr, &TilePlace);
			}
		}
	}
}

/*void Enemy()
{

}*/

//OnTriggerEnter
int Trigger(int x, int y)
{
	for (int x1 = 0; x1 < 30; x1++)
	{
		for (int y1 = 0; y1 < 20; y1++)
		{
			if (Level1[x1][y1] == 8)
			{
				if (abs(y - y1 * 50) < 30 and abs(x - x1 * 50) < 30) { return 1; }
			}
		}
	}
}

//Can player move?
bool CanUp(int x, int y)
{
	if (y < 75) { return false; }
	for (int x1 = 0; x1 < 30; x1++)
	{
		for (int y1 = 0; y1 < 20; y1++)
		{
			if (Level1[x1][y1] == 2)
			{
				if (abs(y - y1 * 50 - 30) < 30 and abs(x - x1 * 50) < 30) { return false; }
			}
		}
	}
	return true;
}
bool CanDown(int x, int y)
{
	if (y > 900) { return false; }
	for (int x1 = 0; x1 < 30; x1++)
	{
		for (int y1 = 0; y1 < 20; y1++)
		{
			if (Level1[x1][y1] == 2)
			{
				if (abs(y - y1 * 50 + 30 - 20) < 30 and abs(x - x1 * 50 - 5) < 30) { return false; }
			}
		}
	}
	return true;
}
bool CanLeft(int x, int y)
{
	if (x < 75) { return false; }
	for (int x1 = 0; x1 < 30; x1++)
	{
		for (int y1 = 0; y1 < 20; y1++)
		{
			if (Level1[x1][y1] == 7)
			{
				if (abs(y - y1 * 50) < 30 and abs(x - x1 * 50 - 50) < 30) { return false; }
			}
		}
	}
	return true;
}
bool CanRight(int x, int y)
{
	if (x > 1400) { return false; }
	for (int x1 = 0; x1 < 30; x1++)
	{
		for (int y1 = 0; y1 < 20; y1++)
		{
			if (Level1[x1][y1] == 7)
			{
				if (abs(y - y1 * 50) < 30 and abs(x - x1 * 50 + 30) < 30) { return false; }
			}
		}
	}
	return true;
}

vector <vector<int>> SpawnPlaces = {{}};

void GetSpawnPos()
{
	vector<int> a = {};
	for (int x = 0; x < 30; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			if (Level1[x][y] == 9)
			{
				a = {};
				a.push_back(x * 50 + 25);
				a.push_back(y * 50 + 25);
				SpawnPlaces.push_back(vector <int>(x, y));
				a = {};
			}
		}
	}
}

SDL_Rect Enemy;

void SpawnEnemy(int &Ex, int &Ey)
{
	if (!SpawnPlaces.empty())
	{
		int i = (rand() % SpawnPlaces.size());
		Ex = SpawnPlaces[i][0];
		Ey = SpawnPlaces[i][1];
	}
}

int main(int argc, char* args[])
{
	GetSpawnPos();
	bool att1 = 0;
	bool att2 = 0;
	bool att3 = 0;
	bool att4 = 0;

	int ttime = 0;
	if (!init()) {
		system("pause");
		quit();
		return 1;
	}

	if (!load()) {
		system("pause");
		quit();
		return 1;
	}

	SDL_Rect bg_Player;
	bg_Player.w = 80;
	bg_Player.h = 80;
	bg_Player.x = 350;
	bg_Player.y = 350;

	Enemy.w = 60;
	Enemy.h = 60;

	int x = 350, y = 350, Ex = 500, Ey = 500;

	bool IsRun = 1;
	SDL_Event event;

	vector <SDL_Surface *> Player_sprites = { IMG_Load("Character1.png"), IMG_Load("Character2.png") };
	SDL_Surface* Death = IMG_Load("Death.png");

	vector <SDL_Surface*> enemy = { IMG_Load("Enemy1.png"), IMG_Load("Enemy2.png") };



	while (IsRun)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT) { IsRun = 0; }
			if (event.type == SDL_KEYDOWN)
			{
				//Move
				if (Alive)
				{
					if (event.key.keysym.sym == SDLK_w)
					{
						if (CanUp(x, y)) { y = y - Speed; }
					}
					if (event.key.keysym.sym == SDLK_s)
					{
						if (CanDown(x, y)) { y = y + Speed; }
					}
					if (event.key.keysym.sym == SDLK_a)
					{
						if (CanLeft(x, y)) { x = x - Speed; }
					}
					if (event.key.keysym.sym == SDLK_d)
					{
						if (CanRight(x, y)) { x = x + Speed; }
					}
				}
				if (event.key.keysym.sym == SDLK_q) { x = 350; y = 350; Alive = true; }
				if (event.key.keysym.sym == SDLK_p) { IsRun = 0; }
			}
		}

		SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 145, 97, 52));

		LoadLevel(Level);

		if (Trigger(x, y) == 1)
		{
			Alive = 0;
		}

		bg_Player.x = x;
		bg_Player.y = y;
		Enemy.x = Ex;
		Enemy.y = Ey;

		ttime++;
		if (Alive) { SDL_BlitScaled(Player_sprites[(ttime / 20) % 2], NULL, scr, &bg_Player); }
		else { SDL_BlitScaled(Death, NULL, scr, &bg_Player); }
		if (EnemyAlive) 
		{
			SDL_BlitScaled(enemy[(ttime / 50) % 2], NULL, scr, &Enemy);
			if (Alive) 
			{
				if (abs(x - Ex) < 60 and abs(y - Ey) < 60) { Alive = 0;  EnemyAlive = 0; }
				if (abs(x - Ex) < 40 && y < Ey) { att1 = 1; }
				if (abs(x - Ex) < 40 && y > Ey) { att2 = 1; }
				if (abs(y - Ey) < 40 && x > Ex) { att3 = 1; }
				if (abs(y - Ey) < 40 && x < Ex) { att4 = 1; }
			}
			if (att1 == 1) { Ey = Ey - 10; }
			if (att2 == 1) { Ey = Ey + 10; }
			if (att3 == 1) { Ex = Ex + 10; }
			if (att4 == 1) { Ex = Ex - 10; }
			if (Ex < 1 || Ey < 1 || Ex > 1500 || Ey > 1000) { EnemyAlive = 0; }
		}
		if (!EnemyAlive) { SpawnEnemy(Ex, Ey); att1 = 0; att2 = 0; att3 = 0; att4 = 0; }

		SDL_UpdateWindowSurface(win);
	}



	quit();
	return 0;
}
