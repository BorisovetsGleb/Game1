#include "Level.h"

vector<vector<int>> room;//<- probably delete these
const vector<vector<int>> roomTypes[] = {room1};//<- probably delete these

SDL_Rect Level::TileRect;
SDL_Rect *const Level::TilePlace = &TileRect;

Level::Level(){
    x = 0;
    y = 0;
    level = { {0, 0}, {0, 0} };//<----- Use generated level not this!
    SetRoom();
}

vector<vector<int>> Level::GetLevel(){
    return roomTypes[level[x][y]];
}

void Level::SetRoom(){
    room = GetLevel();
}

void Level::LoadRoom(){
	TileRect.w = 50;
	TileRect.h = 50;
    for (int x1 = 0; x1 < 30; x1++){
        for (int y1 = 0; y1 < 20; y1++){
            TileRect.x = x1 * 50 + 50;
            TileRect.y = y1 * 50 + 50;
            SDL_RenderCopy(renderer, textures[room1[x1][y1] + 1], NULL, TilePlace);
        }
	}
}
