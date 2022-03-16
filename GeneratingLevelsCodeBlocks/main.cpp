#include "main.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;


int main(int argc, char* args[]){
    window = SDL_CreateWindow("GG_Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_MAXIMIZED);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    bool isRun = true;
    SDL_Event event;
    LoadSprites();
    Player player(350, 350, 80, 80, 15);
    Level level;

    while(isRun){
        while (SDL_PollEvent(&event) != 0){
            if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                isRun = 0;
            }
        }

        SDL_RenderClear(renderer);
        Level::LoadRoom();
        player.Move();
        SDL_RenderPresent(renderer);
    }
    return 0;
}


