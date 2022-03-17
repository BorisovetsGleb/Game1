#include "Menu.h"
#include "winuser.h"

Menu::Menu()
{
	rectanglePointer = new SDL_Rect;
	rectanglePointer->w = 400;
	rectanglePointer->h = 100;
	rectanglePointer->x = 750;
	rectanglePointer->y = 450;
	texturePointer = textures[17];
}

bool Menu::Out(bool IsTupped)
{
	SDL_Rect* Button{};

	int x, y;
	SDL_Event event{};
	SDL_PollEvent(&event);
	SDL_GetMouseState(&x, &y);
	cout << "x= " << x << "  " << "y= " << y << endl;
	if (IsTupped)
	{
		if (x > 750 && y > 450 && x < 1150 && y < 550)
		{
			return 1;
		}
	}
	SDL_RenderCopy(renderer, textures[17], NULL, Button);
	SDL_RenderCopy(renderer, textures[18], NULL, rectanglePointer);
	return 0;
}
