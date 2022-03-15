#include "Level.h"

Room* currentRoom;//<- probably delete these
vector<Room*> Level::levelRooms;
const vector<vector<int>> roomTypes[] = {room1};//<- probably delete these

SDL_Rect Level::TileRect;
SDL_Rect *const Level::TilePlace = &TileRect;

Level::Level(){
    x = 0;
    y = 0;
    GenerateLevel();//<----- Use generated level not this!
    SetRoom();
}

//recursive method for generating a level with a random amount of rooms
//room is the room we are creating
void Level::GenerateRoom(Room* room){
    //process 4 exits
    for(int i = 0; i < 4; i++){
        if(room->exits[i] == NULL){
            if(randomNumber(1, 5) == 1){
                Room* newRoom;
                newRoom->setExit((i < 2) ? i + 2 : i - 2, room);
                GenerateRoom(newRoom);
                room->setExit(i, newRoom);
                levelRooms.push_back(newRoom);
            }
        }
    }
    //end
}

void Level::GenerateLevel(){
    Room* startRoom;//room with 4 exits i hope
    currentRoom = startRoom;
    GenerateRoom(startRoom);
    levelRooms.push_back(startRoom);
}

void Level::SetRoom(){
    currentRoom = levelRooms[];
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
