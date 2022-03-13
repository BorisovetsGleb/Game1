#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "main.h"

extern const vector<vector<int>> roomTypes[];//array of every possible room
extern vector<vector<int>> room;//a room the player is currently in
extern vector<vector<int>> room1;//room type 1

class Level{
private:
    vector<vector<int>> level;//vector of rooms on a level
    int x;//player position on a level(in which room he is by x) LEVEL: {0, 1} - one empty room and three
    int y;//player position on a level(in which room he is by y)        {1, 1}   are the same type

public:
    Level();
    void generateLevel();//generates a random level of rooms
    vector<vector<int>> GetLevel();//returns a vector<vector<int>> of a level,
    //depending on the index of room the player is in
    void GetRoom();//returns a room the player is currently in
    void SetRoom();//changes current room
    static void LoadRoom();//loads room into an array
    static SDL_Rect TileRect;
    static SDL_Rect *const TilePlace;
    void DeleteLevel();//deletes level vector
};

#endif // LEVEL_H_INCLUDED
