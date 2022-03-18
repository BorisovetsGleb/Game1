#include "main.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
const Uint8* keyboardKeysPressed = SDL_GetKeyboardState(NULL);
vector <FireBallEnemy*> Enemies{};
//Level level;

void GenerateEnemies()
{
    for (int i = 0; i < 6; i++)
    {
        FireBallEnemy* enemy1 = new FireBallEnemy(200, 200, 50, 50, 1, 1);
        Enemies.push_back(enemy1);
        FireBallEnemy* enemy = new FireBallEnemy(randomNumber(20, 1500), randomNumber(20, 1000), 50, 50, randomNumber(0, 1), randomNumber(0, 1));
        Enemies.push_back(enemy);
    }
}

int main(int argc, char* args[]){
    window = SDL_CreateWindow("GG_Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_MAXIMIZED);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    bool Win = 0;
    bool isRun = true;
    bool InMenu = true;
    bool IsTupped = 0;
    int kolOfDeathEnemies = 0;
    SDL_Event event;
    LoadSprites();
    Player* player = new Player(350, 350, 72, 40, 5);
    Level level;
    Throwable* stone = new Throwable(400, 400, 44, 32, 2, 'c');
    Menu* menu = new Menu();
    while(isRun){
        while (SDL_PollEvent(&event) != 0){
            if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                isRun = 0;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                IsTupped = 1;
                GenerateEnemies();
            }
            else { IsTupped = 0; }
        }
        SDL_RenderClear(renderer);
        if (InMenu)
        {
            bool b1 = menu->Out(IsTupped);
            if (b1) { InMenu = 0; }
        }
        else if(!InMenu && !Win)
        {
            Level::LoadRoom();
            kolOfDeathEnemies = 0;
            for (int i = 0; i < Enemies.size(); i++)
            {
                if (Enemies[i]->Alive == 0) { kolOfDeathEnemies++; }
            }
            if (kolOfDeathEnemies == Enemies.size()) { Win = 1; }
            stone->Move();
            for (int i = 0; i < Enemies.size(); i++)
            {
                Enemies[i]->FireEnemy();
            }
            player->Move();
            stone->CheckCollision();
        }
        else
        {
            InMenu = 1;
            Win = 0;
        }
        SDL_RenderPresent(renderer);
    }
    return 0;
}


