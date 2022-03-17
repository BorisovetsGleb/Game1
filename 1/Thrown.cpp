#include "Object.h"

Throw::Throw(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	rectangle.w = w;
	rectangle.h = h;
	rectanglePointer = &rectangle;
	texturePointer = textures[static_cast<std::vector<SDL_Texture *, std::allocator<SDL_Texture *>>::size_type>(rand()%7) + 18];
}

void Throw::PickUp()
{
	//if()
}

void Throw::IsPickedUp(int x1, int y1)
{
	this->x2 = x2;
	this->y2 = y2;
	if (abs(x - x2) > 50 && abs(y - y2) > 50)
	{
		cout << "USED" << endl;
		rectangle.x = x;
		rectangle.y = y;
		SDL_RenderCopy(renderer, texturePointer, NULL, rectanglePointer);
	}
}
