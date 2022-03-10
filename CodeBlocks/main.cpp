#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include "F1.h"
#define WINDOW_WIDHT = 600

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int Speed = 5;
int x = 350, y = 350;
int Level = 1;


SDL_Window* win = NULL;
SDL_Surface* scr = NULL;
SDL_Surface* flower = NULL;
SDL_Surface* level = NULL;
SDL_Surface* s1 = NULL;

vector <const char*> ground =
{
    "Ground1.png", "Ground2.png",
    "Ground3.png", "Ground1.png",
    "Ground4.png", "Ground5.png",
    "Ground1.png"
};

vector <SDL_Surface*> sprites =
{
    IMG_Load(ground[rand() % 7]), IMG_Load("Wall1.png"),
    IMG_Load("WallYgol1.png"), IMG_Load("WallYgol4.png"),
    IMG_Load("WallYgol2.png"), IMG_Load("WallYgol3.png"),
    IMG_Load("Wall4.png")
};

vector<vector<int>>Level1 =
{
    {3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 4},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
    {5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6}
};

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "Can't init video: " << SDL_GetError() << std::endl;
        return false;
    }

    int flags = IMG_INIT_PNG;
    if (!(IMG_Init(flags) & flags))
    {
        std::cout << "Can't init image: " << IMG_GetError() << std::endl;
        return false;
    }

    win = SDL_CreateWindow("GG_Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_MAXIMIZED);
    if (win == NULL)
    {
        std::cout << "Can't create window: " << SDL_GetError() << std::endl;
        return false;
    }

    scr = SDL_GetWindowSurface(win);

    return true;
}

bool load()
{
    flower = IMG_Load("Character1.png");
    if (flower == NULL)
    {
        std::cout << "Can't load: " << IMG_GetError() << std::endl;
    }

    flower = SDL_ConvertSurface(flower, scr->format, NULL);
    if (flower == NULL)
    {
        std::cout << "Can't convert: " << SDL_GetError() << std::endl;
    }

    return true;
}

void quit()
{
    SDL_FreeSurface(flower);

    SDL_FreeSurface(scr);
    SDL_DestroyWindow(win);

    SDL_Quit();
    IMG_Quit();
}

void LoadLevel(int levelID)
{
    SDL_Rect TilePlace;
    TilePlace.w = 55;
    TilePlace.h = 55;
    if (levelID == 1)
    {
        for (int x1 = 0; x1 < 30; x1++)
        {
            for (int y1 = 0; y1 < 20; y1++)
            {
                TilePlace.x = x1 * 50 + 25;
                TilePlace.y = y1 * 50 + 25;
                SDL_BlitScaled(sprites[Level1[x1][y1] - 1], NULL, scr, &TilePlace);
            }
        }
    }
}

void Enemy()
{

}

bool CanUp(int y)
{
    if (y < 75)
    {
        return false;
    }
    return true;
}

bool CanDown(int y)
{
    if (y > 900)
    {
        return false;
    }
    return true;
}

bool CanLeft(int x)
{
    if (x < 75)
    {
        return false;
    }
    return true;
}

bool CanRight(int x)
{
    if (x > 1400)
    {
        return false;
    }
    return true;
}

void Move(const Uint8 keys[])
{
    //Move
    if (keys[SDL_SCANCODE_W])
    {
        if (CanUp(y))
        {
            y = y - Speed;
        }
    }
    if (keys[SDL_SCANCODE_S])
    {
        if (CanDown(y))
        {
            y = y + Speed;
        }
    }
    if (keys[SDL_SCANCODE_A])
    {
        if (CanLeft(x))
        {
            x = x - Speed;
        }
    }
    if (keys[SDL_SCANCODE_D])
    {
        if (CanRight(x))
        {
            x = x + Speed;
        }
    }
}

int main(int argc, char* args[])
{
    //int level = 1;
    int ttime = 0;
    if (!init())
    {
        system("pause");
        quit();
        return 1;
    }

    if (!load())
    {
        system("pause");
        quit();
        return 1;
    }

    SDL_Rect bg_Player;
    bg_Player.w = 80;
    bg_Player.h = 80;
    bg_Player.x = 350;
    bg_Player.y = 350;

    bool IsRun = 1;
    SDL_Event event;

    const Uint8 *keysPressed = SDL_GetKeyboardState(NULL);

    //vector <const char *> sprites = { "Character1.png", "Character2.png" };
    SDL_Surface* sprites[2] = { IMG_Load("Character1.png"), IMG_Load("Character2.png") };
    while (IsRun)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                IsRun = 0;
            }

        }
        Move(keysPressed);
        SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 0, 0, 0));

        LoadLevel(Level);

        bg_Player.x = x;
        bg_Player.y = y;

        ttime++;
        flower = sprites[(ttime / 10) % 2];
        SDL_BlitScaled(flower, NULL, scr, &bg_Player);
        SDL_UpdateWindowSurface(win);
    }

    quit();
    return 0;
}
