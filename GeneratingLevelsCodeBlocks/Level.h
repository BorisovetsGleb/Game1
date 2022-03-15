#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "main.h"

extern const vector<vector<int>> roomTypes[];//array of every possible room
extern vector<vector<int>> room1;//room type 1

extern Room* currentRoom;//a room the player is currently in

class Room;//<---- probably get rid of this shit(but it doesn't compile without that)

class Level{
private:
    static vector<Room*> levelRooms;//vector of rooms on a level
    void GenerateRoom(Room* room);//as GenerateLevel() creates a starter room, i should use this to generate other rooms
    int x;//player position on a level(in which room he is by x) LEVEL: {0, 1} - one empty room and three
    int y;//player position on a level(in which room he is by y)        {1, 1}   are the same type

public:
    Level();
    void GenerateLevel();//generates a random level of rooms
    void GetRoom();//returns a room the player is currently in
    void SetRoom();//changes current room
    static void LoadRoom();//loads room into an array
    static SDL_Rect TileRect;
    static SDL_Rect *const TilePlace;
    void DeleteLevel();//deletes level vector and all pointers!!!!!!!
};

#endif // LEVEL_H_INCLUDED
