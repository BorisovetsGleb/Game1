#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#pragma once

#include "Libraries.h"
class Object{
public:
    virtual void Logic();
    string type;
    int x;//position X          //<-- probably delete this
    int y;//position Y          //<-- probably delete this
    int width;//player width    //<-- probably delete this
    int height;//player height  //<-- probably delete this
    int halfHeight;
    int halfWidth;
    int gridX;//position x on a grid
    int gridY;//position y on a grid
    SDL_Rect* rectanglePointer;//pointer to player rectangle(kostil')
    int speed;//player speed
    SDL_Texture* texturePointer;//player texture pointer
private:
protected:

};

#endif // OBJECT_H_INCLUDED
