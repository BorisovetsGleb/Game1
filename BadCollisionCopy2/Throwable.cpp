#include "Throwable.h"
#include "Player.h"
#include "Level.h"
#include "Extern.h"
Throwable::Throwable(int x, int y, int width, int height, double acceleration, char throwableType){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->acceleration = acceleration;
    halfWidth = width / 2;
    halfHeight = height / 2;
    isPicked = false;
    isIdle = true;
    velocity = 0;
    gridX = x / 50;
    gridY = y / 50;
    rectanglePointer = new SDL_Rect;
    rectanglePointer->x = x;
    rectanglePointer->y = y;
    rectanglePointer->w = width;
    rectanglePointer->h = height;
    if(throwableType == 'c')
        texturePointer = textures[14];
}

bool Throwable::CanUp(){
    for(int i = 1; i <= 6; i++)
        if(currentRoom->roomStructure[y / 50 - 1][x / 50 - 1] == i ||
            currentRoom->roomStructure[y / 50 - 1][(x + halfWidth) / 50 - 1] == i ||
            currentRoom->roomStructure[y / 50 - 1][(x + width) / 50 - 1] == i)
            return false;
	return true;
}
bool Throwable::CanDown(){
    for(int i = 1; i <= 6; i++)
        if(currentRoom->roomStructure[(y + height) / 50 - 1][x / 50 - 1] == i ||
            currentRoom->roomStructure[(y + height) / 50 - 1][(x + halfWidth) / 50 - 1] == i ||
            currentRoom->roomStructure[(y + height) / 50 - 1][(x + width) / 50 - 1] == i)
            return false;;
	return true;
}
bool Throwable::CanLeft(){

    for(int i = 1; i <= 6; i++)
        if(currentRoom->roomStructure[y / 50 - 1][x / 50 - 1] == i ||
            currentRoom->roomStructure[(y + halfHeight) / 50 - 1][x / 50 - 1] == i ||
            currentRoom->roomStructure[(y + height) / 50 - 1][x / 50 - 1] == i)
            return false;
    return true;
}
bool Throwable::CanRight(){

        for(int i = 1; i <= 6; i++)
            if(currentRoom->roomStructure[y / 50 - 1][(x + width) / 50 - 1 ] == i ||
               currentRoom->roomStructure[(y + halfHeight) / 50 - 1][(x + width) / 50 - 1] == i ||
               currentRoom->roomStructure[(y + height) / 50 - 1][(x + width) / 50 - 1] == i)
                return false;
    return true;
}


void Throwable::Logic(){
    if(!isPicked){
        SDL_RenderCopy(renderer, texturePointer, NULL, rectanglePointer);
        CheckCollision();
        if(!isIdle)
            Move();
    }
}

void Throwable::Move(){
    for(int i = 1; i <= 6; i++){
        if(currentRoom->roomStructure[y / 50 - 1][(x + halfWidth) / 50 - 1] == i ||
           currentRoom->roomStructure[(y + height) / 50 - 1][(x + halfWidth) / 50 - 1] == i){
            velocityY *= -1;
            velocityY -= (abs(velocityY) / velocityY) * accelerationY * 50;
            velocityX -= (abs(velocityX) / velocityX) * accelerationX * 50;
        }
        else if(currentRoom->roomStructure[(y + halfHeight) / 50 - 1][x / 50 - 1] == i ||
                currentRoom->roomStructure[(y + halfHeight) / 50 - 1][(x + width) / 50 - 1] == i){
            velocityX *= -1;
            velocityY -= (abs(velocityY) / velocityY) * accelerationY * 50;
            velocityX -= (abs(velocityX) / velocityX) * accelerationX * 50;
        }
        else if(currentRoom->roomStructure[(y + 10) / 50 - 1][(x + 10) / 50 - 1] == i ||
                currentRoom->roomStructure[(y + 10) / 50 - 1][(x + width - 10) / 50 - 1] == i ||
                currentRoom->roomStructure[(y + - 10 + height) / 50 - 1][(x + 10) / 50 - 1] == i ||
                currentRoom->roomStructure[(y + - 10 +height) / 50 - 1][(x + width - 10) / 50 - 1] == i){
            velocityX *= -1;
            velocityY *= -1;
            velocityY -= (abs(velocityY) / velocityY) * accelerationY * 50;
            velocityX -= (abs(velocityX) / velocityX) * accelerationX * 50;
        }
    }
    x += velocityX;
    y += velocityY;
    velocityX -= (abs(velocityX) / velocityX) * accelerationX;
    velocityY -= (abs(velocityY) / velocityY) * accelerationY;
    if(abs(velocityX) < 1 && abs(velocityY) < 1)
        isIdle = true;
    rectanglePointer->x = x;
    rectanglePointer->y = y;
}
void Throwable::CheckCollision(){
    if(isIdle){
        if(players[0]->x + players[0]->width >= x &&
           x + width >= players[0]->x &&
           players[0]->y + players[0]->height >= y &&
           y + height >= players[0]->y){
            if(keyboardKeysPressed[SDL_SCANCODE_E] && players[0]->item == NULL){
                players[0]->item = this;
                isPicked = true;
            }
        }
    }
}

