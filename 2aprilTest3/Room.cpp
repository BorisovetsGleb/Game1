#include "Room.h"

Room::Room(){
    exits = {NULL, NULL, NULL, NULL};
    cout << "Room constructed: " << this << endl;
    roomStructure = room1;
}
//direction - place of an exit; room - that we enter
void Room::setExit(int direction, Room* room){
    switch(direction){
        case 0:
            for(int i = 8; i <= 11; i++)
                roomStructure[i][0] = 0;
            exits[0] = room;
            break;
        case 1:
            for(int i = 13; i <= 16; i++)
                roomStructure[0][i] = 0;
            exits[1] = room;
            break;
        case 2:
            for(int i = 8; i <= 11; i++)
                roomStructure[i][29] = 0;
            exits[2] = room;
            break;
        case 3:
            for(int i = 13; i <= 16; i++)
                roomStructure[19][i] = 0;
            exits[3] = room;
            break;
    }
}

template <typename T>
void emptyVector(vector<T> &vec){
    vector<T>().swap(vec);
}

Room::~Room(){
    cout << "room destructor\n";
    emptyVector(entities);
    emptyVector(exits);
    emptyVector(roomStructure);
}
