#include "Player.h"
#include "Extern.h"
#include "Level.h"
int errorX = 0;
int errorY = 0;
vector<Player*> players = {};

Player::Player(int x, int y, int width, int height, int speed){
    this->x = x;//<-- maybe delete this
    this->y = y;//<-- maybe delete this
    this->width = width;//<-- maybe delete this
    this->height = height;//<-- maybe delete this
    this->speed = speed;
    players.push_back(this);
    gridX = x / 50;
    gridY = y / 50;
    rectanglePointer = new SDL_Rect;
    rectanglePointer->w = width;
	rectanglePointer->h = height;
    texturePointer = textures[0];
}

bool Player::CanUp(){
    //if (currentRoom->roomStructure[gridY - 1][gridX] == 1 || currentRoom->roomStructure[gridY - 1][gridX] == 2 || currentRoom->roomStructure[gridY - 1][gridX] == 3 || currentRoom->roomStructure[gridY - 1][gridX] == 4 || currentRoom->roomStructure[gridY - 1][gridX] == 5 || currentRoom->roomStructure[gridY - 1][gridX] == 6)
    if (errorY < 70)
        for(int i = 1; i <= 6; i++)
            if(currentRoom->roomStructure[gridY - 1][gridX])
                return false;
	return true;
}
bool Player::CanDown(){
    //if (currentRoom->roomStructure[gridY + 1][gridX] == 1 || currentRoom->roomStructure[gridY + 1][gridX] == 2 || currentRoom->roomStructure[gridY + 1][gridX] == 3 || currentRoom->roomStructure[gridY + 1][gridX] == 4 || currentRoom->roomStructure[gridY + 1][gridX] == 5 || currentRoom->roomStructure[gridY + 1][gridX] == 6)
    if (errorY == 110)
        for(int i = 1; i <= 6; i++)
            if(currentRoom->roomStructure[gridY + 1][gridX])
                return false;
	/*if (y > 900)
        return false;*/
	return true;
}
bool Player::CanLeft(){
    //if (currentRoom->roomStructure[gridY][gridX - 1] == 1 || currentRoom->roomStructure[gridY][gridX] == 1 || currentRoom->roomStructure[gridY][gridX - 1] == 2 || currentRoom->roomStructure[gridY][gridX - 1] == 3 || currentRoom->roomStructure[gridY][gridX - 1] == 4 || currentRoom->roomStructure[gridY][gridX - 1] == 5 || currentRoom->roomStructure[gridY][gridX - 1] == 6)
    if(errorX == 111)
        for(int i = 1; i <= 6; i++)
            if(currentRoom->roomStructure[gridY][gridX - 1] == i ||
               currentRoom->roomStructure[gridY][gridX])
                return false;
    return true;
}
bool Player::CanRight(){
    //if (currentRoom->roomStructure[gridY][gridX + 1] == 1 || currentRoom->roomStructure[gridY][gridX + 1] == 2 || currentRoom->roomStructure[gridY][gridX + 1] == 3 || currentRoom->roomStructure[gridY][gridX + 1] == 4 || currentRoom->roomStructure[gridY][gridX + 1] == 5 || currentRoom->roomStructure[gridY][gridX + 1] == 6)
    if(errorX == 96)
        for(int i = 1; i <= 6; i++)
            if(currentRoom->roomStructure[gridY][gridX + 1] ||
               currentRoom->roomStructure[gridY][gridX])
                return false;
    return true;
}

void Player::Move(){
    //Move
    if (keyboardKeysPressed[SDL_SCANCODE_W]){
        if (CanUp())
            y = y - speed;
    }
    if (keyboardKeysPressed[SDL_SCANCODE_S]){
        if (CanDown())
            y = y + speed;
    }
    if (keyboardKeysPressed[SDL_SCANCODE_A]){
        if (CanLeft())
            x = x - speed;
    }
    if (keyboardKeysPressed[SDL_SCANCODE_D]){
        if (CanRight())
            x = x + speed;
    }
    if(SDL_GetError() != NULL){
        //cout << SDL_GetError() <<endl;
    }
    gridX = (x - 20) / 50;
    gridY = (y - 20) / 50;
    if(gridX == 0){
        x += 1380;
        Level::SetRoom(currentRoom->exits[0]);
    }
    else if(gridY == 0){
        y += 900;
        Level::SetRoom(currentRoom->exits[1]);
    }
    else if(gridX == 29){
        x -= 1380;
        Level::SetRoom(currentRoom->exits[2]);
    }
    else if(gridY == 19){
        y -= 900;
        Level::SetRoom(currentRoom->exits[3]);
    }
    rectanglePointer->x = x;
    rectanglePointer->y = y;
    errorX = abs((x + width / 2) - (gridX * 50 - 25));
    errorY = abs((y + height / 2) - (gridY * 50 - 25));
    cout << "ERRORS: \n" << errorX << endl << errorY << endl << endl;
    SDL_RenderCopy(renderer, texturePointer, NULL, rectanglePointer);

}

