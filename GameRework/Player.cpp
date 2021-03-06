#include "Object.h"

int errorX = 0;
int errorY = 0;

Player::Player(int x, int y, int width, int height, int speed){
    this->x = x;//<-- maybe delete this
    this->y = y;//<-- maybe delete this
    this->width = width;//<-- maybe delete this
    this->height = height;//<-- maybe delete this
    this->speed = speed;
    Alive = 1;
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
    //if (errorY < 1)
    //{
        if (room1[gridX][gridY - 1] == 1 || room1[gridX][gridY - 1] == 2 || room1[gridX][gridY - 1] == 3 || room1[gridX][gridY - 1] == 4 || room1[gridX][gridY - 1] == 5 || room1[gridX][gridY - 1] == 6)
           return false;
   //}
	return true;
}
bool Player::CanDown()
{
    if (errorY < 1)
    {
        if (room1[gridX][gridY + 1] == 1 || room1[gridX][gridY + 1] == 2 || room1[gridX][gridY + 1] == 3 || room1[gridX][gridY + 1] == 4 || room1[gridX][gridY + 1] == 5 || room1[gridX][gridY + 1] == 6)
            return false;
    }
	/*if (y > 900)
        return false;*/
	return true;
}
bool Player::CanLeft()
{
    if (room1[gridX - 1][gridY] == 1 || room1[gridX - 1][gridY] == 2 || room1[gridX - 1][gridY] == 3 || room1[gridX - 1][gridY] == 4 || room1[gridX - 1][gridY] == 5 || room1[gridX - 1][gridY] == 6)
    {
        return false;
    }
	/*if (x < 75)
        return false;
	*/
    return true;
}
bool Player::CanRight()
{
    /*
	if (x > 1400)
        return false;
	*/
    if (room1[gridX + 1][gridY] == 1 || room1[gridX + 1][gridY] == 2 || room1[gridX + 1][gridY] == 3 || room1[gridX + 1][gridY] == 4 || room1[gridX + 1][gridY] == 5 || room1[gridX + 1][gridY] == 6)
    {
        return false;
    }
    return true;
}


void Player::CollisionGrid()
{
    if (room1[gridX][gridY] == 7) { Alive = 0; texturePointer = textures[14]; }
}



void Player::Move(){
    //Move
    if (Alive)
    {
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
        CollisionGrid();
    }
    if (keyboardKeysPressed[SDL_SCANCODE_Q])
    {
        Alive = 1;
        x = 350;
        y = 350;
        texturePointer = textures[0];
    }
    if(SDL_GetError() != NULL){
        cout << SDL_GetError() <<endl;
    }
    rectangle.x = x;
    rectangle.y = y;
    gridX = ((x + 40 - 50) / 50);
    gridY = ((y + 40 - 50) / 50);
    //errorX = abs(x - (gridX * 50 * 50));
    errorY = abs(y - (gridY * 50 + 50));
    cout << "gridX: " << gridX << endl;
    cout << "gridY: " << gridY << endl << endl;
    SDL_RenderCopy(renderer, texturePointer, NULL, rectanglePointer);
    //if(CollisionGrid() == 7){}
}
