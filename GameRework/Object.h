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

class Player : public Object{
public:
    void Move();
    Player(int x, int y, int width, int height, int speed);
private:
    int x;//position X          //<-- maybe delete this
    int y;//position Y          //<-- maybe delete this
    int width;//player width    //<-- maybe delete this
    int height;//player height  //<-- maybe delete this
    int speed;//player speed
    SDL_Surface* surfacePointer;//pointer to player surface     //<-- maybe delete this
    SDL_Rect rectangle;//player rectangle on which texture is put and which determines position of a player
    SDL_Rect* rectanglePointer;//pointer to player rectangle(kostil')

    SDL_Texture* texturePointer;//player texture pointer
    const Uint8* keyboardKeysPressed = SDL_GetKeyboardState(NULL);//array of keys pressed
};

#endif // OBJECT_H_INCLUDED
