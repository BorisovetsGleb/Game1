#include "Object.h"

Player::Player(int x, int y, int width, int height, int speed){
    this->x = x;//<-- maybe delete this
    this->y = y;//<-- maybe delete this
    this->width = width;//<-- maybe delete this
    this->height = height;//<-- maybe delete this
    this->speed = speed;
    gridX = x % 50;
    gridY = y % 50;
    rectangle.w = width;
	rectangle.h = height;
//	rectangle.x = x;
//	rectangle.y = y;
	rectanglePointer = &rectangle;
    texturePointer = textures[0];
}

bool Player::CanUp()
{
	if (room1[gridX][gridY] == 1 || room1[gridX][gridY] == 2 || room1[gridX][gridY] == 3 || room1[gridX][gridY] == 4 || room1[gridX][gridY] == 5 || room1[gridX][gridY] == 6)
        return false;
	return true;
}
bool Player::CanDown()
{
	if (y > 900)
        return false;
	return true;
}
bool Player::CanLeft()
{
	if (x < 75)
        return false;
	return true;
}
bool Player::CanRight()
{
	if (x > 1400)
        return false;
	return true;
}



void Player::Move(){
    //Move
    if (keyboardKeysPressed[SDL_SCANCODE_W])
    {
        //cout << keyboardKeysPressed[SDL_SCANCODE_W];
        if (CanUp())
            y = y - speed;
    }
    if (keyboardKeysPressed[SDL_SCANCODE_S])
    {
        //cout << keyboardKeysPressed[SDL_SCANCODE_S];
        if (CanDown())
            y = y + speed;
    }
    if (keyboardKeysPressed[SDL_SCANCODE_A])
    {
        //cout << keyboardKeysPressed[SDL_SCANCODE_A];
        if (CanLeft())
            x = x - speed;
    }
    if (keyboardKeysPressed[SDL_SCANCODE_D])
    {
        //cout << keyboardKeysPressed[SDL_SCANCODE_D];
        if (CanRight())
            x = x + speed;
    }
    if(SDL_GetError() != NULL){
        cout << SDL_GetError();
    }
    rectangle.x = x;
    rectangle.y = y;
    gridX = x / 50;
    gridY = y / 50;
    cout << "gridX: " << gridX << endl;
    cout << "gridY: " << gridY << endl << endl;
    SDL_RenderCopy(renderer, texturePointer, NULL, rectanglePointer);
}

