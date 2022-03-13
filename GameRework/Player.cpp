#include "Object.h"

Player::Player(int x, int y, int width, int height, int speed){
    this->x = x;//<-- maybe delete this
    this->y = y;//<-- maybe delete this
    this->width = width;//<-- maybe delete this
    this->height = height;//<-- maybe delete this
    this->speed = speed;
    rectangle.w = width;
	rectangle.h = height;
	rectangle.x = x;
	rectangle.y = y;
	rectanglePointer = &rectangle;
    texturePointer = textures[0];
}

bool CanUp(int x, int y)
{
	if (y < 75)
        return false;
	return true;
}
bool CanDown(int x, int y)
{
	if (y > 900)
        return false;
	return true;
}
bool CanLeft(int x, int y)
{
	if (x < 75)
        return false;
	return true;
}
bool CanRight(int x, int y)
{
	if (x > 1400)
        return false;
	return true;
}



void Player::Move(){
    //Move
    if (keyboardKeysPressed[SDL_SCANCODE_W])
    {
        cout << keyboardKeysPressed[SDL_SCANCODE_W];
        if (CanUp(x, y))
            y = y - speed;
    }
    if (keyboardKeysPressed[SDL_SCANCODE_S])
    {
        cout << keyboardKeysPressed[SDL_SCANCODE_S];
        if (CanDown(x, y))
            y = y + speed;
    }
    if (keyboardKeysPressed[SDL_SCANCODE_A])
    {
        cout << keyboardKeysPressed[SDL_SCANCODE_A];
        if (CanLeft(x, y))
            x = x - speed;
    }
    if (keyboardKeysPressed[SDL_SCANCODE_D])
    {
        cout << keyboardKeysPressed[SDL_SCANCODE_D];
        if (CanRight(x, y))
            x = x + speed;
    }
    if(SDL_GetError() != NULL){
        cout << SDL_GetError();
    }
    rectangle.x = x;
    rectangle.y = y;
    SDL_RenderCopy(renderer, texturePointer, NULL, rectanglePointer);
}

