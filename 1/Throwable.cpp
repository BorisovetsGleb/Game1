#include "Throwable.h"
#include "Player.h"
#include "Extern.h"
Throwable::Throwable(int x, int y, int width, int height, int acceleration, char throwableType){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->acceleration = acceleration;
    isPicked = false;
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

void Throwable::Move(){
    if(!isPicked)
        SDL_RenderCopy(renderer, texturePointer, NULL, rectanglePointer);

    // << "moved";
}

void Throwable::CheckCollision(){
    if(!isPicked &&
       players[0]->x + players[0]->width >= x &&
       x + width >= players[0]->x &&
       players[0]->y + players[0]->height >= y &&
       y + height >= players[0]->y){
        //picked up but actually still in the same place!!!!!!
        cout << endl << "Player:" << endl << "X: "<< players[0]->x << endl << "Y: " << players[0]->y << endl << players[0]->width << endl << players[0]->height;
        cout << endl << "Stone:" << endl << "X: "<< x << endl << "Y: " << y << endl << width << endl << height;
        if(keyboardKeysPressed[SDL_SCANCODE_E]){
            cout << endl << players[0]->item << endl;
            players[0]->item = this;
            isPicked = true;
            cout << "picked" << endl;
            cout << players[0]->item;
        }
    }
}
