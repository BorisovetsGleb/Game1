#include <iostream>
#include <vector>
#include <SDL.h>

using namespace std;

void it_horisontalLine(SDL_Renderer* ren, int x, int y, int len)
{
    SDL_RenderDrawLine(ren, x, y, x + len, y);
}

void it_verticalLine(SDL_Renderer* ren, int x, int y, int len)
{
    SDL_RenderDrawLine(ren, x, y, x, y + len);
}

void VerticalDiagram(SDL_Renderer* ren, vector <int> a)
{
    for (size_t i = 0; i < a.size() - 1; i++)
    {
        SDL_RenderDrawLine(ren, i * 10, (50 - a[i]) * 10, (i + 1) * 10, (50 - a[i + 1]) * 10);
    }
}

void line(float x1, float y1, float x2, float y2, SDL_Renderer* ren)
{
    int iX1 = roundf(x1);
    int iX2 = roundf(x2);
    int iY1 = roundf(y1);
    int iY2 = roundf(y2);

    int deltaX = abs(iX1 - iX2);
    int deltaY = abs(iY1 - iY2);

    int lenght = max(deltaX, deltaY);

    if (lenght == 0) { SDL_RenderDrawPoint(ren, iX1, iY1); return; }

    double dx = (x2 - x1) / lenght;
    double dy = (y2 - y1) / lenght;

    double x = x1;
    double y = y1;

    lenght++;
    while (lenght--)
    {
        x += dx;
        y += dy;
        SDL_RenderDrawPoint(ren, x, y);
    }
}

void horisontalDiagram(SDL_Renderer* ren, vector <int> a)
{
    for (size_t i = 0; i < a.size() - 1; i++)
    {
        line(a[i] * 10, i * 10, a[i + 1] * 10, (i + 1) * 10, ren);
    }
}

void DrawLines(SDL_Renderer* ren, int x1, int y1, int x2, int y2, int col)
{
    for (size_t i = 0; i < col; i++)
    {
        line(x1 + i, y1 + i * 10, x2 + i, y2 + i * 10, ren);
    }
}

void Rgadient(SDL_Renderer* ren)
{
    for (int i = 0; i < 256; i++)
    {
        SDL_SetRenderDrawColor(ren, 0, i * 0.9, i, 0xFF);
        line(i, 0, i, 255, ren);
    }
}

int main(int argc, char** argv)
{
    int width = 1000;
    int height = 1000;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        return 1;
    }
    SDL_Surface* surface = NULL;
    SDL_Window* window = NULL;
    SDL_Renderer* ren = NULL;

    window = SDL_CreateWindow("Main", 5, 10, height, width, SDL_WINDOW_SHOWN);
    ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    surface = SDL_GetWindowSurface(window);

    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(ren);
    SDL_Rect rect1 = { 0, 0, 1000, 1000 };
    SDL_RenderFillRect(ren, &rect1);

    SDL_SetRenderDrawColor(ren, 0xff, 0xff, 0xff, 0xff);

    //SDL_RenderDrawPoint(ren, 500, 500);

    //SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0x00);

    //it_horisontalLine(ren, 100, 10, -100);
    //it_verticalLine(ren, 20, 20, 200);

    //VerticalDiagram(ren, {1, 2, 4, 10, 3, 2, 1, 0, 7, 6, 4, 3, 1, 3, 4, 7, 8, 10, 11, 5, 3, 2, 1});

    //horisontalDiagram(ren, {0, 10, 19, 27, 34, 40, 45, 49, 52, 54, 55, 54, 52, 49, 45, 40, 34, 27, 19, 10, 0});
    //line(0, 0, 200, 30, ren);
    //DrawLines(ren, 10, 10, 200, 300, 5);
    //line(10, 10, 100, 100, ren);
    //line(50, 10, 50, 100, ren);
    //line(25, 10, 75, 100, ren);
    //line(10, 10, 200, 100, ren);
    vector<vector<int>> mass = { {10, 10}, {110, 10}, {210, 10}, {210, 110}, {210, 210}, {110, 210}, {10, 210}, {10, 110} };
    for (int i = 0; i < mass.size(); i++) {
        //line(110, 110, mass[i][0], mass[i][1], ren);
        //SDL_Delay(1000);
        //SDL_SetRenderDrawColor(ren, 255 - i * 30, 255, 255, 255);
    }
    /*line(500, 500, 500, 400, ren);
    line(500, 500, 400, 500, ren);
    line(500, 500, 600, 500, ren);
    line(500, 500, 500, 600, ren);
    line(500, 500, 420, 450, ren);
    line(500, 500, 450, 420, ren);
    line(500, 500, 450, 580, ren);
    line(500, 500, 420, 550, ren);
    line(500, 500, 550, 580, ren);
    line(500, 500, 580, 550, ren);
    line(500, 500, 550, 420, ren);
    line(500, 500, 580, 450, ren);*/
    //DrawLines(ren, 500, 500, 400, 550, 50);
    //line(110, 110, 210, 165, ren);

    //SDL_SetRenderDrawColor(ren, 255, 0, 255, 255);
    //line(110, 110, 165, 210, ren);
    //DrawCircle(ren, 100, 100, 100);

    Rgadient(ren);


    SDL_UpdateWindowSurface(window);
    SDL_RenderPresent(ren); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ALWAYS USE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    SDL_Delay(7000);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
