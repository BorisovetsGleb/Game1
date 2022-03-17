#include "Player.h"
#include "Libraries.h"
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
    halfWidth = width / 2;
    halfHeight = height / 2;
    this->speed = speed;
    players.push_back(this);
    gridX = (x + halfWidth) / 50;
    gridY = (y + halfHeight) / 50;
    rectanglePointer = new SDL_Rect;
    rectanglePointer->w = width;
	rectanglePointer->h = height;
    texturePointer = textures[0];
}

bool Player::CanUp(){
    for(int i = 1; i <= 6; i++)
        if(currentRoom->roomStructure[y / 50 - 1][(x + halfWidth) / 50 - 1] == i ||
           currentRoom->roomStructure[y / 50 - 1][(x + width - 5) / 50 - 1] == i ||
           currentRoom->roomStructure[y / 50 - 1][(x + 5) / 50 - 1] == i)
            return false;
	return true;
}
bool Player::CanDown(){
    for(int i = 1; i <= 6; i++)
        if(currentRoom->roomStructure[(y + height) / 50 - 1][(x + halfWidth) / 50 - 1] == i ||
           currentRoom->roomStructure[(y + height) / 50 - 1][(x + width - 5) / 50 - 1] == i ||
           currentRoom->roomStructure[(y + height) / 50 - 1][(x + 5) / 50 - 1] == i)
            return false;
	return true;
}
bool Player::CanLeft(){

    for(int i = 1; i <= 6; i++)
        if(currentRoom->roomStructure[(y + halfHeight) / 50 - 1][x / 50 - 1] == i ||
           currentRoom->roomStructure[(y + 5) / 50 - 1][x / 50 - 1] == i ||
           currentRoom->roomStructure[(y - 5 + height) / 50 - 1][x / 50 - 1] == i)
            return false;
    return true;
}
bool Player::CanRight(){

    for(int i = 1; i <= 6; i++)
        if(currentRoom->roomStructure[(y + halfHeight) / 50 - 1][(x + width) / 50 - 1 ] == i ||
           currentRoom->roomStructure[(y + 5) / 50 - 1][(x + width) / 50 - 1 ] == i ||
           currentRoom->roomStructure[(y - 5 + height) / 50 - 1][(x + width) / 50 - 1] == i)
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
    gridX = (x + halfWidth) / 50;
    gridY = (y + halfHeight) / 50;
//    cout << "GRID COORDINATES: \n" << gridX << endl << gridY << endl << endl;
    //cout << "ERRORS: \n" << errorX << endl << errorY << endl << endl;
//    if(gridX == 0 && gridY >= 8 && gridY <= 11){
//        x += 1380;
//        Level::SetRoom(currentRoom->exits[0]);
//    }
//    else if(gridY == 0 && gridX >= 13 && gridX <= 16){
//        y += 900;
//        Level::SetRoom(currentRoom->exits[1]);
//    }
//    else if(gridX == 29 && gridY >= 8 && gridY <= 11){
//        x -= 1380;
//        Level::SetRoom(currentRoom->exits[2]);
//    }
//    else if(gridY == 19 && gridX >= 13 && gridX <= 16){
//        y -= 900;
//        Level::SetRoom(currentRoom->exits[3]);
//    }
    rectanglePointer->x = x;
    rectanglePointer->y = y;
}

void Player::Throw(){
    if(keyboardKeysPressed[SDL_SCANCODE_UP] && item != NULL){
        item->x = x;
        item->y = y;
        item->rectanglePointer->x = x;
        item->rectanglePointer->y = y;
        item->throwAngle = 45;//degrees
        item->velocity = 10;
        item->velocityX = item->velocity * cos(item->throwAngle * 0.017);
        item->velocityY = item->velocity * -1 * sin(item->throwAngle * 0.017);//-1 is because y axis is directed downwards
                                                                              //this flips y and let's us work with normal
                                                                              //coordinate system
        item->accelerationX = item->acceleration * cos(item->throwAngle * 0.017);
        item->accelerationY = item->acceleration * sin(item->throwAngle * 0.017);
        item->isPicked = false;
        item->isIdle = false;
        item = NULL;
    }
}

void Player::Logic(){
    Move();
    if(item != NULL)
        Throw();
    SDL_RenderCopy(renderer, texturePointer, NULL, rectanglePointer);
}
