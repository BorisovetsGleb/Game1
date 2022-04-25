#ifndef MAPELEMENT_H_INCLUDED
#define MAPELEMENT_H_INCLUDED

#include "UIElement.h"

class MapElement : public UIELement{
public:
    MapElement(int x, int y, int width, int height);
    void Logic();
private:
    SDL_Rect* frameRectanglePointer;
    SDL_Rect* mapPlayerRectanglePointer;
};

#endif // MAPELEMENT_H_INCLUDED
