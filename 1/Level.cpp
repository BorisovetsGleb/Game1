#include "Level.h"

Room* currentRoom;//<- probably delete these
vector<Room*> Level::levelRooms;
const vector<vector<int>> roomTypes[] = { room1 };//<- probably delete these

SDL_Rect Level::TileRect;
SDL_Rect* const Level::TilePlace = &TileRect;

Level::Level() {
    cout << "Level constructed!" << endl;
    x = 0;//delete
    y = 0;//delete

    GenerateLevel();//<----- Use generated level not this!
    cout << endl << "Level generated!" << endl;
    cout << endl << levelRooms.size() << endl;
    SetRoom(currentRoom);
    printArray(currentRoom->exits);
    cout << endl;
    for (int i = 0; i < 4; i++) {
        printArray(currentRoom->exits[i]->exits);
    }
}

//recursive method for generating a level with a random amount of rooms
//room is the room we are creating
void Level::GenerateRoom(Room* room, int counter) {
    counter++;
    cout << "vizvali" << endl;
    //cout << room->exits[0];
    //cout << "Array here!";
   //process 4 exits
    if (counter != 4) {
        for (int i = 0; i < 4; i++) {
            if (room->exits[i] == NULL) {
                if (randomNumber(1, counter) == 1) {

                    Room* newRoom = new Room();
                    int buffer;
                    if (i < 2)
                        buffer = i + 2;
                    else
                        buffer = i - 2;
                    //                    ((i < 2) ? i + 2 : i - 2)
                    newRoom->setExit(buffer, room);
                    if (newRoom->exits[buffer] == NULL)
                        cout << endl << "No exit ;)" << endl;
                    else
                        cout << room << "  " << newRoom->exits[buffer] << endl;
                    room->setExit(i, newRoom);
                    if (room->exits[i] == NULL)
                        cout << endl << "No exit2!" << endl;
                    else
                        cout << newRoom << "  " << room->exits[i] << endl;
                    GenerateRoom(newRoom, counter);

                    levelRooms.push_back(newRoom);
                }
            }
        }
    }
    //end
}

void Level::GenerateLevel() {
    Room* startRoom = new Room();//room with 4 exits i hope
    cout << startRoom->exits.size() << endl;
    //cout << "Coordinates set!";
    currentRoom = startRoom;
    cout << currentRoom << endl;
    //cout << startRoom->exits[0];
//    cout << "pointed";
    GenerateRoom(startRoom, 0);
    levelRooms.push_back(startRoom);

}

void Level::SetRoom(Room* room) {
    cout << endl << "exits" << endl;
    if (room == NULL)
        cout << endl << "Null :(";
    else
        currentRoom = room;
}

void Level::LoadRoom() {
    TileRect.w = 50;
    TileRect.h = 50;
    for (int y1 = 0; y1 < 20; y1++) {
        for (int x1 = 0; x1 < 30; x1++) {
            TileRect.x = x1 * 50 + 50;
            TileRect.y = y1 * 50 + 50;
            SDL_RenderCopy(renderer, textures[currentRoom->roomStructure[y1][x1] + 1], NULL, TilePlace);
        }
    }
}