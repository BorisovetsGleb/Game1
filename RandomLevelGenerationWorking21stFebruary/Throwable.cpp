#include "Throwable.h"
#include "Player.h"
#include "Level.h"
#include "Extern.h"

vector<char> Throwable::throwableTypes = {'c', 't', 'w'};//c - stone, s - stick, w - sword

Throwable::Throwable(int x, int y, double acceleration, char throwableType){
    this->x = x;
    this->y = y;
    this->acceleration = acceleration;

    isPicked = false;
    isIdle = true;
    velocity = 0;
    gridX = x / 50;
    gridY = y / 50;
    rectanglePointer = new SDL_Rect;
    rectanglePointer->x = x;
    rectanglePointer->y = y;
    //cout << throwableType << endl;
    if(throwableType == 't'){
        texturePointer = textures[15];
        width = 48;
        height = 30;
    }
    else if(throwableType == 'w'){
        texturePointer = textures[16];
        width = 16;
        height = 44;
    }
    else{
        texturePointer = textures[14];
        width = 44;
        height = 32;
    }
    rectanglePointer->w = width;
    rectanglePointer->h = height;
    halfWidth = width / 2;
    halfHeight = height / 2;
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
        if(!isIdle)
            Move();
        else
            CheckCollision();
    }
}

void Throwable::Move(){
    cout << "moved" << endl;
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
            cout << "collide" << endl;
            if(players[0]->item == NULL)
                cout << "NULL" << endl;
            if(keyboardKeysPressed[SDL_SCANCODE_E] && players[0]->item == NULL){
                cout << "pick up" << endl;
                players[0]->item = this;
                cout << players[0]->item;
                isPicked = true;
            }
        }
    }
}

