#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include "main.h"

class Room{
public:
    Room();//constructor for class Room
    ~Room();
    vector<Room*> exits;//vector of exits from the room 0-left 1-upper 2-right 3-down exit(-s)
    //vector<int> ints;
    int numberOfExits;//number of exits in the room
    vector<vector<int>> roomStructure;//structure of the room
    void setExit(int direction, Room* room);//deletes one or several walls in room vector
                                //and adds pointer to other room
                                //0-left 1-upper 2-right 3-down exit(-s)
    int roomType;//type of room
    vector<Object*> entities;
};

#endif // ROOM_H_INCLUDED
