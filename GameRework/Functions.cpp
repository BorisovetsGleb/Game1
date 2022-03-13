#include "main.h"

SDL_Surface* surface = NULL;
SDL_Texture* texture = NULL;

vector<SDL_Texture*> textures = {};

bool LoadTexture(const char* imagePath){
    surface = IMG_Load(imagePath);
    if(surface == NULL){
        std::cout << "Can't create surface! " << SDL_GetError() << std::endl;
        return false;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture == NULL){
        std::cout << "Can't create texture!" << SDL_GetError() << std::endl;
        return false;
    }
    textures.push_back(texture);
    texture = NULL;
    SDL_FreeSurface(surface);
    std::cout << imagePath << " - loaded!" << std::endl;
    return true;
}

void LoadSprites(){
    LoadTexture("Textures\\Character1.png");
    //0
    LoadTexture("Textures\\Ground1.png");
    LoadTexture("Textures\\WallUpDown.png");
	LoadTexture("Textures\\WallUpperLeftCorner.png");
	LoadTexture("Textures\\WallDownLeftCorner.png");
	LoadTexture("Textures\\WallUpperRightCorner.png");
	LoadTexture("Textures\\WallDownRightCorner.png");
	LoadTexture("Textures\\WallLeftRight.png");
	LoadTexture("Textures\\GroundSpikes.png");
	LoadTexture("Textures\\EnemySpawner.png");
	LoadTexture("Textures\\Ground2.png");
	LoadTexture("Textures\\Ground3.png");
	LoadTexture("Textures\\Ground4.png");
	LoadTexture("Textures\\Ground5.png");
}


