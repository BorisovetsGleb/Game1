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
    LoadTexture("Textures\\Character11.png");//0
    //0
    LoadTexture("Textures\\Ground1.png");//1
    LoadTexture("Textures\\WallUpDown.png");//2
	LoadTexture("Textures\\WallUpperLeftCorner.png");//3
	LoadTexture("Textures\\WallDownLeftCorner.png");//4
	LoadTexture("Textures\\WallUpperRightCorner.png");//5
	LoadTexture("Textures\\WallDownRightCorner.png");//6
	LoadTexture("Textures\\WallLeftRight.png");//7
	LoadTexture("Textures\\GroundSpikes.png");//8
	LoadTexture("Textures\\EnemySpawner.png");//9
	LoadTexture("Textures\\Ground2.png");//10
	LoadTexture("Textures\\Ground3.png");//11
	LoadTexture("Textures\\Ground4.png");//12
	LoadTexture("Textures\\Ground5.png");//13
    LoadTexture("Textures\\Death1.png");//14
    LoadTexture("Textures\\Character3.png");//15
    LoadTexture("Textures\\Death2.png");//16
    LoadTexture("Textures\\Bottle.png");//17
    LoadTexture("Textures\\Rock.png");//18
    LoadTexture("Textures\\Stick.png");//19
    LoadTexture("Textures\\Sword.png");//20
    LoadTexture("Textures\\Unknown1.png");//21
    LoadTexture("Textures\\Unknown2.png");//22
    LoadTexture("Textures\\Unknown3.png");//23
    LoadTexture("Textures\\Unknown4.png");//24
}

int randomNumber(int lowerBorder, int upperBorder) {
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
        (std::mt19937::result_type)
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()
            ).count() +
        (std::mt19937::result_type)
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch()
            ).count());

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(lowerBorder, upperBorder);
    return distrib(gen);
}

void printArray(const vector<Room*>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;
    cout << endl;
}

