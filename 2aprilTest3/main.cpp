#include "main.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int *numberKeysPressed;
const Uint8* keyboardKeysPressed = SDL_GetKeyboardState(numberKeysPressed);
int main(int argc, char* args[]){
    window = SDL_CreateWindow("GG_Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_MAXIMIZED);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    srand(time(0));
    bool isRun = true;
    SDL_Event event;
    LoadSprites();
    Player* player = new Player(350, 350, 72, 44, 5);
    MapElement* GUIMap = new MapElement(1575, 50, 36, 30);
    //Throwable* stone = new Throwable(400, 400, 0.02, 's');
    Level level;
    while(isRun){
        while (SDL_PollEvent(&event) != 0){
            if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                isRun = 0;
            }
        }

        SDL_RenderClear(renderer);
        if(players[0]->onLevel == true){
            Level::LoadRoom();
            for(int i = 0; i < currentRoom->entities.size(); i++)
                currentRoom->entities[i]->Logic();
            player->Logic();
            GUIMap->Logic();
        }
        else{
            if(keyboardKeysPressed[SDL_SCANCODE_0])
                Level::GenerateLevel();
        }

        SDL_RenderPresent(renderer);
    }
    return 0;
}


