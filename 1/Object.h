#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#pragma once
#include "main.h"

class Object{
private:
protected:
    string type;
public:
//    void setWindow(SDL_Window* Window);
//    void setRenderer(SDL_Renderer* Renderer);
//    static SDL_Window* window;
//    static SDL_Renderer* renderer;
};

class Throw : public Object
{
public:
    void IsPickedUp(int x1, int y1);
    Throw(int x, int y, int w, int h);
    bool picketUp = 0;
private:
    void PickUp();
    int x;
    int y;
    int w;
    int h;
    int x2;
    int y2;
    SDL_Rect rectangle;//player rectangle on which texture is put and which determines position of a player
    SDL_Rect* rectanglePointer;//pointer to player rectangle(kostil')
    SDL_Texture* texturePointer;//player texture pointer
};

class Player : public Object{
public:
    void Move();
    Player(int x, int y, int width, int height, int speed);
    int ColOfAttack;
    //friend Throw::IsPickedUp();
    int x;//position X          //<-- probably delete this
    int y;//position Y          //<-- probably delete this
private:
    bool Alive;
    int gridX;//position x on a grid
    int gridY;//position y on a grid
    int width;//player width    //<-- probably delete this
    int height;//player height  //<-- probably delete this
    int speed;//player speed
    SDL_Surface* surfacePointer;//pointer to player surface     //<-- probably delete this
    SDL_Rect rectangle;//player rectangle on which texture is put and which determines position of a player
    SDL_Rect* rectanglePointer;//pointer to player rectangle(kostil')
    SDL_Texture* texturePointer;//player texture pointer
    const Uint8* keyboardKeysPressed = SDL_GetKeyboardState(NULL);//array of keys pressed
    bool CanUp();
    bool CanDown();
    bool CanLeft();
    bool CanRight();
    void CollisionGrid();
    Room* CurrentRoom;
};

#endif // OBJECT_H_INCLUDED
