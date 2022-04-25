#include "Throwable.h"
#include "Player.h"
#include "Level.h"
#include "Extern.h"

vector<char> Throwable::throwableTypes = {'c', 't', 'w'};//c - stone, s - stick, w - sword

Throwable::Throwable(int x, int y, double acceleration, char throwableType) : Object(x, y){
    this->acceleration = acceleration;
    isPicked = false;
    isIdle = true;
    velocity = 0;
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
    velocityX = 0;
    velocityY = 0;
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
    // cout << "moved" << endl;
    for(int i = 1; i <= 6; i++){
        if(currentRoom->roomStructure[y / 50 - 1][(x + halfWidth) / 50 - 1] == i ||
           currentRoom->roomStructure[(y + height) / 50 - 1][(x + halfWidth) / 50 - 1] == i){
            cout << "COLLIDED!COLLIDED!COLLIDED!COLLIDED!COLLIDED!\n";

            cout << "\nvelocityY\n" << velocityY << endl;
            velocityY *= -1;
            accelerationY *= -1;
            velocityY -= accelerationY * 10;
            cout << velocityY << endl << accelerationY << "\nvelocityX\n" << velocityX << endl << endl;
            //velocityX -= accelerationX;
        }
        else if(currentRoom->roomStructure[(y + halfHeight) / 50 - 1][x / 50 - 1] == i ||
                currentRoom->roomStructure[(y + halfHeight) / 50 - 1][(x + width) / 50 - 1] == i){


            cout << "asdadasfafaf";
            cout << "velocityX\n" << velocityX << endl;
            velocityX *= -1;
            accelerationX *= -1;
            velocityX -= accelerationX;
            cout << velocityY << endl << endl;
            //velocityY -= accelerationY;

        }
        else if(currentRoom->roomStructure[(y + 10) / 50 - 1][(x + 10) / 50 - 1] == i ||
                currentRoom->roomStructure[(y + 10) / 50 - 1][(x + width - 10) / 50 - 1] == i ||
                currentRoom->roomStructure[(y + - 10 + height) / 50 - 1][(x + 10) / 50 - 1] == i ||
                currentRoom->roomStructure[(y + - 10 +height) / 50 - 1][(x + width - 10) / 50 - 1] == i){
            cout << "asdadasfafaf";
            velocityX *= -1;
            velocityY *= -1;
            accelerationY *= (velocityY / abs(velocityY));
            accelerationX *= (velocityX / abs(velocityX));
            velocityY -= accelerationY;
            velocityX -= accelerationX;

        }
    }
    if(abs(velocityX) < 1.5 && abs(velocityY) < 1.5){
        isIdle = true;
        velocityX = 0;
        velocityY = 0;
    }
    else{
        cout << endl << "else\n" << accelerationY << endl << velocityY << endl;
        velocityY -= accelerationY;
        cout << velocityY << endl << endl;
        velocityX -= accelerationX;
        x += velocityX;
        y += velocityY;
    }
    rectanglePointer->x = x;
    rectanglePointer->y = y;
    //cout << "\nACCELERATION:\n" << accelerationX << endl << accelerationY << endl << endl;
}
void Throwable::CheckCollision(){
    if(isIdle){
        if(players[0]->x + players[0]->width >= x &&
           x + width >= players[0]->x &&
           players[0]->y + players[0]->height >= y &&
           y + height >= players[0]->y){
            //cout << "collide" << endl;
            if(players[0]->item == NULL)
                //cout << "NULL" << endl;
            if(keyboardKeysPressed[SDL_SCANCODE_E] && players[0]->item == NULL){
                //cout << "pick up" << endl;
                players[0]->item = this;
                //cout << players[0]->item << endl;
                isPicked = true;
            }
        }
    }
}

