#include "Room.h"

Room::Room(){
    vector<Room*> exits = {NULL, NULL, NULL, NULL};
}
//direction - place of an exit; room - that we enter
void Room::setExit(int direction, Room* room){
    switch(direction){
        case 0:
            for(int i = 13; i <= 16; i++)
                roomStructure[i][0] = 0;
            exits[0] = room;
            break;
        case 1:
            for(int i = 8; i <= 11; i++)
                roomStructure[0][i] = 0;
            exits[1] = room;
            break;
        case 2:
            for(int i = 13; i <= 16; i++)
                roomStructure[i][19] = 0;
            exits[2] = room;
            break;
        case 3:
            for(int i = 8; i <= 11; i++)
                roomStructure[29][i] = 0;
            exits[3] = room;
            break;
    }
}
