#include "main.h"
#include "Functions.h"
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
    LoadTexture("Textures\\WallDownLeftCorner.png");
	LoadTexture("Textures\\WallUpperLeftCorner.png");
	LoadTexture("Textures\\WallUpperRightCorner.png");
	LoadTexture("Textures\\WallDownRightCorner.png");
	LoadTexture("Textures\\WallLeftRight.png");
	LoadTexture("Textures\\GroundSpikes.png");
	LoadTexture("Textures\\EnemySpawner.png");
	LoadTexture("Textures\\Ground2.png");
	LoadTexture("Textures\\Ground3.png");
	LoadTexture("Textures\\Ground4.png");
	LoadTexture("Textures\\Ground5.png");

	LoadTexture("Textures\\Stone.png");
    LoadTexture("Textures\\Stick.png");
    LoadTexture("Textures\\Sword.png");

    LoadTexture("Textures\\Exit.png");//index 17

    LoadTexture("Textures\\Enemy1.png");
    LoadTexture("Textures\\Death.png");
}

//int randomNumber(int lowerBorder, int upperBorder){
//    std::random_device rd;
//        std::mt19937::result_type seed = rd() ^ (
//                (std::mt19937::result_type)
//                std::chrono::duration_cast<std::chrono::seconds>(
//                    std::chrono::system_clock::now().time_since_epoch()
//                    ).count() +
//                (std::mt19937::result_type)
//                std::chrono::duration_cast<std::chrono::microseconds>(
//                    std::chrono::high_resolution_clock::now().time_since_epoch()
//                    ).count() );
//
//        std::mt19937 gen(seed);
//        std::uniform_int_distribution<unsigned> distrib(lowerBorder, upperBorder);
//        return distrib(gen);
//}

int randomNumber(int lowerBorder, int upperBorder){
    if(upperBorder == 0)
        return 0;
    return (rand() % upperBorder + lowerBorder);
}

void printArray(){
    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++){
            cout << Level::levelRooms[y][x] << " ";
        }
    cout << endl;
    }
}

//template <typename T>
//void emptyVector(vector<T> &vec){
//    vector<T>().swap(vec);
//}
//
//void emptyExits(vector<Room*> &vec){
//    vector<Room*>().swap(vec);
//}

void printVector(const vector<Room*> &arr){
    for(int  i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;
    cout << endl;
}
