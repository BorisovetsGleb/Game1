#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "main.h"

extern const vector<vector<int>> roomTypes[];//array of every possible room
extern vector<vector<int>> room1;//room type 1

class Room;//<---- probably get rid of this shit(but it doesn't compile without that)

extern Room* currentRoom;//a room the player is currently in

class Level{
public:
    static int numberOfEnemies;
    static Room* levelRooms[9][9];
    Level();
    static void GenerateLevel();//generates a random level of rooms
    static void SetRoom(Room* room);//changes current room
    static void LoadRoom();//renders room
    static void DeleteLevel();//deletes level vector and all pointers!!!!!!!
private:
    static void GenerateRoom(Room* room, int counter, int roomX, int roomY);//as GenerateLevel() creates a starter room, i should use this to generate other rooms
                                                                     //roomX and roomY helps us to generate geometrically right level
    int x;//player position on a level(in which room he is by x) LEVEL: {0, 1} - one empty room and three
    int y;//player position on a level(in which room he is by y)        {1, 1}   are the same type
    static bool hasExit;//if level has an exit
    static SDL_Rect *const tile;
    static vector<vector<Room*>> roomsDepth;
};

#endif // LEVEL_H_INCLUDED
