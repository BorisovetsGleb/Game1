#include "Level.h"
#include "Throwable.h"

Room* currentRoom;//<- probably delete these
const vector<vector<int>> roomTypes[] = {room1};//<- probably delete these
SDL_Rect *const Level::tile = new SDL_Rect();
bool Level::hasExit;
int Level::numberOfEnemies;
vector<vector<Room*>> Level::roomsDepth;

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
    if(roomsDepth.size() < counter)
        roomsDepth.push_back(vector<Room*>());
    roomsDepth[counter - 1].push_back(room);
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
            room->entities.push_back(new Throwable(numberX, numberY, 0.02, Throwable::throwableTypes[randomNumber(0, 3)]));
        }
    }
//    1 - 4 enemies
    if(counter != 1){
        for(int i = 0; i < 4; i++){
            if(randomNumber(1, 5) == 1){
                numberX = randomNumber(100, 1300);
                numberY = randomNumber(100, 900);
                while(room->roomStructure[numberY / 50][numberX / 50] != 0){
                    numberX = randomNumber(100, 1300);
                    numberY = randomNumber(100, 900);
                }
                numberOfEnemies++;
                room->entities.push_back(new FireBallEnemy(numberX, numberY));
            }
        }
    }
    levelRooms[roomY][roomX] = room;
    //process 4 exits

    if(counter < 4){
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

    //DEBUG!!!!!!! DON'T DELETE srand(3);
    //srand(3);
    numberOfEnemies = 0;
    Room* startRoom = new Room();//room with 4 exits i hope
    hasExit = false;
    cout << startRoom->exits.size() << endl;
    currentRoom = startRoom;
    cout << currentRoom << endl;
    //generate all ropms
    GenerateRoom(startRoom, 0, 4, 4);
    //generate an exit
    roomsDepth[roomsDepth.size() - 1][randomNumber(0, roomsDepth[roomsDepth.size() - 1].size() - 1)]->roomStructure[5][5] = 16;
    roomsDepth = {};
    players[0]->x = 350;
    players[0]->y = 350;
    players[0]->onLevel = true;
    cout << endl << "numberOfEnemies!!!!!:  " << numberOfEnemies << endl;
}

void Level::SetRoom(Room* room){
    cout << endl << "exits" << endl;
    if(room == NULL)
        cout << endl << "Null :(";
    else
        currentRoom = room;
}

void Level::LoadRoom(){
	tile->w = 50;
	tile->h = 50;
    for (int y1 = 0; y1 < 20; y1++){
        for (int x1 = 0; x1 < 30; x1++){
            tile->x = x1 * 50 + 50;
            tile->y = y1 * 50 + 50;
            SDL_RenderCopy(renderer, textures[currentRoom->roomStructure[y1][x1] + 1], NULL, tile);
        }
	}
}

void Level::DeleteLevel(){
    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++){
            if(levelRooms[y][x] != NULL){
                delete levelRooms[y][x];
                levelRooms[y][x] = NULL;
            }
        }
    }
    players[0]->onLevel = false;
}
