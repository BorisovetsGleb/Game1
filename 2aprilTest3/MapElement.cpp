#include "MapElement.h"
#include "Level.h"

MapElement::MapElement(int x, int y, int width, int height) : UIELement(x, y, width, height){
    frameRectanglePointer = new SDL_Rect;
    mapPlayerRectanglePointer = new SDL_Rect;
    mapPlayerRectanglePointer->w = 12;
    mapPlayerRectanglePointer->h = 12;
    //mapPlayerRectanglePointer->y = 100;
    frameRectanglePointer->w = width * 9;
    frameRectanglePointer->h = width * 9;
    frameRectanglePointer->x = x;
    frameRectanglePointer->y = y;
    this->y += 30;
}
//12w : 10h
void MapElement::Logic(){


    for(int mapY = 0; mapY < 9; mapY++){
        rectanglePointer->y = y + height * mapY;
        for(int mapX = 0; mapX < 9; mapX++){
            rectanglePointer->x = x + width * mapX;
            if(Level::levelRooms[mapY][mapX] != NULL){
                if(currentRoom == Level::levelRooms[mapY][mapX]){//if player in current room
                    //edit! kostil'!
                    mapPlayerRectanglePointer->x = x + width * mapX + (players[0]->x / (width + width * 8 / 12));
                    mapPlayerRectanglePointer->y = y + height * mapY + (players[0]->y / (height + height * 8 / 10));
                    SDL_RenderCopy(renderer, textures[21], NULL, rectanglePointer);
                    SDL_RenderCopy(renderer, textures[23], NULL, mapPlayerRectanglePointer);
                }
                else
                    SDL_RenderCopy(renderer, textures[20], NULL, rectanglePointer);
            }
            //SDL_RenderCopy(renderer, textures[21], NULL, rectanglePointer);
        }
    }
    SDL_RenderCopy(renderer, textures[22], NULL, frameRectanglePointer);
    rectanglePointer->x = x;
    rectanglePointer->y = y;
}
