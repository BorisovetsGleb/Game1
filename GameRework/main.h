#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
using namespace std;

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <vector>

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern vector<SDL_Texture*> textures;
extern vector<SDL_Surface*> sprites;

#include "Level.h"
#include "Functions.h"
#include "Object.h"



#endif // MAIN_H_INCLUDED
