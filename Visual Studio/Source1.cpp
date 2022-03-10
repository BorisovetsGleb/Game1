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
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
		{5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6}
};

vector <const char*> ground = { "Ground1.png", "Ground2.png", "Ground3.png", "Ground1.png", "Ground4.png", "Ground5.png", "Ground1.png" };

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
	IMG_Load("GroundAttack.png")
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
bool CanUp(int y)
{
	if (y < 75) { return false; }
	return true;
}
bool CanDown(int y)
{
	if (y > 900) { return false; }
	return true;
}
bool CanLeft(int x)
{
	if (x < 75) { return false; }
	return true;
}
bool CanRight(int x)
{
	if (x > 1400) { return false; }
	return true;
}

int main(int argc, char* args[])
{
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

	SDL_Rect Enemy;
	Enemy.w = 60;
	Enemy.h = 60;
	Enemy.x = 500;
	Enemy.y = 500;

	int x = 350, y = 350;

	bool IsRun = 1;
	SDL_Event event;

	vector <SDL_Surface *> Player_sprites = { IMG_Load("Character1.png"), IMG_Load("Character2.png") };
	SDL_Surface* Death = IMG_Load("Death.png");

	SDL_Surface* enemy = IMG_Load("Enemy1.png");

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
						if (CanUp(y)) { y = y - Speed; }
					}
					if (event.key.keysym.sym == SDLK_s)
					{
						if (CanDown(y)) { y = y + Speed; }
					}
					if (event.key.keysym.sym == SDLK_a)
					{
						if (CanLeft(x)) { x = x - Speed; }
					}
					if (event.key.keysym.sym == SDLK_d)
					{
						if (CanRight(x)) { x = x + Speed; }
					}
				}
				else if (event.key.keysym.sym == SDLK_q) { x = 350; y = 350; Alive = true; }
			}
		}

		SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 0, 0, 0));

		LoadLevel(Level);

		if (Trigger(x, y) == 1)
		{
			Alive = 0;
		}

		bg_Player.x = x;
		bg_Player.y = y;

		ttime++;
		if (Alive) { SDL_BlitScaled(Player_sprites[(ttime / 20) % 2], NULL, scr, &bg_Player); }
		else { SDL_BlitScaled(Death, NULL, scr, &bg_Player); }
		SDL_BlitScaled(enemy, NULL, scr, &Enemy);
		SDL_UpdateWindowSurface(win);
	}

	quit();
	return 0;
}
