#include "Level.h"
#include "Throwable.h"

Room* currentRoom;//<- probably delete these
Room* Level::levelRooms[9][9] = {
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
};
const vector<vector<int>> roomTypes[] = {room1};//<- probably delete these

SDL_Rect Level::TileRect;
SDL_Rect *const Level::TilePlace = &TileRect;

Level::Level(){
    cout << "Level constructed!" << endl;
    x = 0;//delete
    y = 0;//delete

    GenerateLevel();//<----- Use generated level not this!
    cout << endl << "Level generated!" << endl;
    SetRoom(currentRoom);
    printVector(currentRoom->exits);
    cout << endl;
    for(int i = 0; i < 4; i++){
        printVector(currentRoom->exits[i]->exits);
    }
}

//recursive method for generating a level with a random amount of rooms
//room is the room where we create passages to other rooms
void Level::GenerateRoom(Room* room, int counter, int roomX, int roomY){
    counter++;
    //cout << "vizvali" << endl;
    int numberX;
    int numberY;
    for(int i = 0; i < 4; i++){
        if(randomNumber(1, 2) == 1){
            numberX = randomNumber(100, 1300);
            numberY = randomNumber(100, 900);
            while(room->roomStructure[numberY / 50][numberX / 50] != 0){
                numberX = randomNumber(100, 1300);
                numberY = randomNumber(100, 900);
            }
            Throwable* entityPointer = new Throwable(numberX, numberY, 0.02, Throwable::throwableTypes[randomNumber(0, 3)]);
            room->entities.push_back(entityPointer);
        }
    }
    levelRooms[roomY][roomX] = room;
    //process 4 exits

    if(counter != 4){
        for(int i = 0; i < 4; i++){
            if(room->exits[i] == NULL){
                cout << "\nROOM:  " << room;
                cout << "\nROOM COORDINATES:\n" << roomX << endl << roomY <<  endl << i << endl;
                if(randomNumber(1, counter) == 1){
                    if(levelRooms[(i == 0 || i == 2) ? roomY : (i == 1) ? roomY - 1 : roomY + 1][(i == 1 || i == 3) ? roomX : (i == 0) ? roomX - 1 : roomX + 1] != NULL){
                        cout << "Already have room there! ROOM: " << levelRooms[(i == 0 || i == 2) ? roomY : (i == 1) ? roomY - 1 : roomY + 1][(i == 1 || i == 3) ? roomX : (i == 0) ? roomX - 1 : roomX + 1] << endl;
                        room->setExit(i, levelRooms[(i == 0 || i == 2) ? roomY : (i == 1) ? roomY - 1 : roomY + 1][(i == 1 || i == 3) ? roomX : (i == 0) ? roomX - 1 : roomX + 1]);
                        levelRooms[(i == 0 || i == 2) ? roomY : (i == 1) ? roomY - 1 : roomY + 1][(i == 1 || i == 3) ? roomX : (i == 0) ? roomX - 1 : roomX + 1]->setExit(((i < 2) ? i + 2 : i - 2), room);
                    }
                    else{
                        Room* newRoom = new Room();
                        room->setExit(i, newRoom);
                        newRoom->setExit(((i < 2) ? i + 2 : i - 2), room);
                        //levelRooms[((i == 0 || i == 2) ? roomY : (i == 1) ? roomY - 1 : roomY + 1)][((i == 1 || i == 3) ? roomX : (i == 0) ? roomX - 1 : roomX + 1)] = newRoom;
                        GenerateRoom(newRoom, counter, ((i == 1 || i == 3) ? roomX : (i == 0) ? roomX - 1 : roomX + 1), ((i == 0 || i == 2) ? roomY : (i == 1) ? roomY - 1 : roomY + 1));
                    }
                }
            }
        }
    }
    //end
}

void Level::GenerateLevel(){
    //srand(time(0));
    //DEBUG!!!!!!! DON'T DELETE
    srand(3);
    Room* startRoom = new Room();//room with 4 exits i hope
    cout << startRoom->exits.size() << endl;
    currentRoom = startRoom;
    cout << currentRoom << endl;
    GenerateRoom(startRoom, 0, 4, 4);
}

void Level::SetRoom(Room* room){
    cout << endl << "exits" << endl;
    if(room == NULL)
        cout << endl << "Null :(";
    else
        currentRoom = room;
}

void Level::LoadRoom(){
	TileRect.w = 50;
	TileRect.h = 50;
    for (int y1 = 0; y1 < 20; y1++){
        for (int x1 = 0; x1 < 30; x1++){
            TileRect.x = x1 * 50 + 50;
            TileRect.y = y1 * 50 + 50;
            SDL_RenderCopy(renderer, textures[currentRoom->roomStructure[y1][x1] + 1], NULL, TilePlace);
        }
	}
}
