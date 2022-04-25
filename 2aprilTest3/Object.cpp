#include "Object.h"

Object::Object(){}

Object::Object(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;//<-- maybe delete this
    this->height = height;//<-- maybe delete this
    halfWidth = width / 2;
    halfHeight = height / 2;
    gridX = (x + halfWidth) / 50;
    gridY = (y + halfHeight) / 50;
    rectanglePointer = new SDL_Rect;
    rectanglePointer->w = width;
	rectanglePointer->h = height;
}

Object::Object(int x, int y){
    this->x = x;
    this->y = y;
    gridX = x / 50;
    gridY = y / 50;
    rectanglePointer = new SDL_Rect;
    rectanglePointer->x = x;
    rectanglePointer->y = y;
}

void Object::Logic(){}
