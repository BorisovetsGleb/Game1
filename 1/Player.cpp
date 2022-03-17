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
    if (errorY < 1)
    {
        if (CurrentRoom->roomStructure[gridX][gridY - 1] == 1 || CurrentRoom->roomStructure[gridX][gridY - 1] == 2 || CurrentRoom->roomStructure[gridX][gridY - 1] == 3 || CurrentRoom->roomStructure[gridX][gridY - 1] == 4 || CurrentRoom->roomStructure[gridX][gridY - 1] == 5 || CurrentRoom->roomStructure[gridX][gridY - 1] == 6)
           return false;
   }
	return true;
}
bool Player::CanDown()
{
    if (errorY < 1)
    {
        if (CurrentRoom->roomStructure[gridX][gridY + 1] == 1 || CurrentRoom->roomStructure[gridX][gridY + 1] == 2 || CurrentRoom->roomStructure[gridX][gridY + 1] == 3 || CurrentRoom->roomStructure[gridX][gridY + 1] == 4 || CurrentRoom->roomStructure[gridX][gridY + 1] == 5 || CurrentRoom->roomStructure[gridX][gridY + 1] == 6)
            return false;
    }
	/*if (y > 900)
        return false;*/
	return true;
}
bool Player::CanLeft()
{
    if (currentRoom->roomStructure[gridX - 1][gridY] == 1 || currentRoom->roomStructure[gridX - 1][gridY] == 2 || currentRoom->roomStructure[gridX - 1][gridY] == 3 || currentRoom->roomStructure[gridX - 1][gridY] == 4 || CurrentRoom->roomStructure[gridX - 1][gridY] == 5 || currentRoom->roomStructure[gridX - 1][gridY] == 6)
    {
        return false;
    }	
    return true;
}
bool Player::CanRight()
{
    if (currentRoom->roomStructure[gridX + 1][gridY] == 1 || currentRoom->roomStructure[gridX + 1][gridY] == 2 || currentRoom->roomStructure[gridX + 1][gridY] == 3 || currentRoom->roomStructure[gridX + 1][gridY] == 4 || currentRoom->roomStructure[gridX + 1][gridY] == 5 || currentRoom->roomStructure[gridX + 1][gridY] == 6)
    {
        return false;
    }
    return true;
}

/*bool Player::CanLeft()
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
}*/


void Player::CollisionGrid()
{
    if (room1[gridX][gridY] == 7) { Alive = 0; texturePointer = textures[14]; }
}



void Player::Move(){
    //Move
    CurrentRoom = currentRoom;
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
    gridX = ((x + 40 - 50) / 55);
    gridY = ((y + 40 - 50) / 55);
    if (gridX == 0) {
        //if()
        x += 1380;
        if (currentRoom->exits[0])
            Level::SetRoom(currentRoom->exits[0]);
    }
    else if (gridY == 0) {
        y += 900;
        if (currentRoom->exits[1])
            Level::SetRoom(currentRoom->exits[1]);
    }
    else if (gridX == 29) {
        x -= 1380;
        if(currentRoom->exits[2])
            Level::SetRoom(currentRoom->exits[2]);
    }
    else if (gridY == 18) {
        y -= 900;
        if (currentRoom->exits[3])
            Level::SetRoom(currentRoom->exits[3]);
    }
    else {
        rectangle.x = x;
        rectangle.y = y;
        errorX = abs(x - (gridX * 50 * 50));
        errorY = abs(y - (gridY * 50 + 50));
        //    cout << "gridX: " << gridX << endl;
        //    cout << "gridY: " << gridY << endl << endl;
    }
    SDL_RenderCopy(renderer, texturePointer, NULL, rectanglePointer);
    //if(CollisionGrid() == 7){}
}
