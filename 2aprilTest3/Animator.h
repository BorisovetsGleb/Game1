#ifndef ANIMATOR_H_INCLUDED
#define ANIMATOR_H_INCLUDED

#include "Libraries.h"

class Animator{
public:
    Animator();
    SDL_Texture* texturePointer;//player texture pointer
    void ChangeSequence(int animationSequence, int framesCount);
protected:
    vector<SDL_Texture*> animationSequences;

    void ChangeFrame();
    SDL_Rect* sourceRectanglePointer;

    int framesCount;//number of frames in sequence
private:
    static int animationSpeed;//in ms
};

#endif // ANIMATOR_H_INCLUDED
