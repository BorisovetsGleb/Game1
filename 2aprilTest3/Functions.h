#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void LoadSprites();//convert all images to SDL_Texture*
//extern enum Sprites{
//
//}
void printVector(const vector<Room*> &arr);
void printArray();

//template <typename T>
//void emptyVector(vector<T> &vec);
//
//void emptyExits(vector<Room*> &vec);

int randomNumber(int lowerBorder, int upperBorder);

#endif // FUNCTIONS_H_INCLUDED
