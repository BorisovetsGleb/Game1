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
    gridX = (x + halfWidth) / 50;
    gridY = (y + halfHeight) / 50;
    throwStarted = false;
    rectanglePointer = new SDL_Rect;
    rectanglePointer->w = width;
	rectanglePointer->h = height;
    texturePointer = textures[0];
    item = NULL;
    players.push_back(this);
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
    //cout << "GRID COORDINATES: \n" << gridX << endl << gridY << endl << endl;
    //cout << "ERRORS: \n" << errorX << endl << errorY << endl << endl;
    if(gridX == 1){
        x += 1380;
        Level::SetRoom(currentRoom->exits[0]);
    }
    else if(gridY == 1){
        y += 880;
        Level::SetRoom(currentRoom->exits[1]);
    }
    else if(gridX == 30){
        x -= 1380;
        Level::SetRoom(currentRoom->exits[2]);
    }
    else if(gridY == 20){
        y -= 900;
        Level::SetRoom(currentRoom->exits[3]);
    }
    rectanglePointer->x = x;
    rectanglePointer->y = y;
}

void Player::Throw(){
    if((keyboardKeysPressed[SDL_SCANCODE_UP] || keyboardKeysPressed[SDL_SCANCODE_DOWN] ||
        keyboardKeysPressed[SDL_SCANCODE_LEFT] || keyboardKeysPressed[SDL_SCANCODE_RIGHT]) && !throwStarted)
        throwStarted = true;
    if(throwStarted){
        if(!(keyboardKeysPressed[SDL_SCANCODE_UP] || keyboardKeysPressed[SDL_SCANCODE_DOWN] ||
             keyboardKeysPressed[SDL_SCANCODE_LEFT] || keyboardKeysPressed[SDL_SCANCODE_RIGHT])){
            item->x = x;
            item->y = y;
            item->rectanglePointer->x = x;
            item->rectanglePointer->y = y;
//            (item->velocityX != 0) item->accelerationX = (item->velocityY / item->velocityX) * 0.02 : item->accelerationX = 0;
//            (item->velocityX != 0) item->accelerationY = (item->velocityY / item->velocityX) * 0.02 : item->accelerationX = 0;
            item->accelerationX = item->velocityX * 0.002;
            item->accelerationY = item->velocityY * 0.002;
            throwStarted = false;
            item->isPicked = false;
            item->isIdle = false;
            item = NULL;
        }
        else{
            //calculating throw angle
            if(keyboardKeysPressed[SDL_SCANCODE_UP] && abs(item->velocityY) < 10){
                item->velocityY += 0.1;
            }
            if(keyboardKeysPressed[SDL_SCANCODE_DOWN] && abs(item->velocityY) < 10){
                item->velocityY -= 0.1;
            }
            if(keyboardKeysPressed[SDL_SCANCODE_LEFT] && abs(item->velocityX) < 10){
                item->velocityX += 0.1;
            }
            if(keyboardKeysPressed[SDL_SCANCODE_RIGHT] && abs(item->velocityX) < 10){
                item->velocityX -= 0.1;
            }
        }
    }
}



void Player::Logic(){
    Move();
    if(item != NULL)
        Throw();
    SDL_RenderCopy(renderer, texturePointer, NULL, rectanglePointer);
}
