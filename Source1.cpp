#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include "F1.h"
#define WINDOW_WIDHT = 600

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* win = NULL;
SDL_Surface* scr = NULL;
SDL_Surface* flower = NULL;

/*void line(float x1, float y1, float x2, float y2, SDL_Renderer* ren)
{
	int iX1 = roundf(x1);
	int iX2 = roundf(x2);
	int iY1 = roundf(y1);
	int iY2 = roundf(y2);

	int deltaX = abs(iX1 - iX2);
	int deltaY = abs(iY1 - iY2);

	int len = max(deltaX, deltaY);
	if (len == 0) { SDL_RenderDrawPoint(ren, x1, y1); }

	double dx = (x2 - x1) / len;
	double dy = (y2 - y1) / len;

	int x = x1;
	int y = y1;
	len++;
	while (len--)
	{
		x = x + dx;
		y = y + dy;
		SDL_RenderDrawPoint(ren, x, y);
	}
}*/

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
	//flower = IMG_LoadGIF_RW(C:\\Users\\Honor\\Desktop\\Character1.gif);
	//flower = IMG_LoadGIF("C:\Users\Honor\Desktop\Character1.gif");
	flower = IMG_Load("C:\\Users\\Honor\\Desktop\\Character1.gif");
	if (flower == NULL) {
		std::cout << "Can't load: " << IMG_GetError() << std::endl;
		//return false;
	}

	flower = SDL_ConvertSurface(flower, scr->format, NULL);
	if (flower == NULL) {
		std::cout << "Can't convert: " << SDL_GetError() << std::endl;
		//return false;
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
	bg_Player.w = 60;
	bg_Player.h = 60;
	bg_Player.x = 0;
	bg_Player.y = 0;

	int x = 0, y = 0;

	bool IsRun = 1;
	SDL_Event event;

	vector <const char *> sprites = { "C:\\Users\\Honor\\Desktop\\Character1.png", "C:\\Users\\Honor\\Desktop\\Character2.png" };

	while (IsRun)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			//if (event.type = SDL_QUIT & ttime > 10) { IsRun = 0; }
			if (event.type = SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_w)
				{
					if (y > 2) { y = y - 2; }
				}
				if (event.key.keysym.sym == SDLK_s)
				{
					y = y + 2;
				}
				if (event.key.keysym.sym == SDLK_a)
				{
					if (x > 2) { x = x - 2; }
				}
				if (event.key.keysym.sym == SDLK_d)
				{
					x = x + 2;
				}
			}
		}

		bg_Player.x = x;
		bg_Player.y = y;

		ttime++;
		flower = IMG_Load(sprites[(ttime / 500) % 2]);
		SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 0, 0, 0));
		SDL_BlitScaled(flower, NULL, scr, &bg_Player);
		SDL_UpdateWindowSurface(win);
	}

	//SDL_BlitScaled(flower, NULL, scr, &bg_flower);

	//SDL_UpdateWindowSurface(win);


	//SDL_Delay(2000);

	quit();

	return 0;
}
