#include "Animator.h"
#include "Extern.h"
//example
//enum Animations{
//    death = { SDL_Texture1, SDL_Texture2, SDL_Texture3 },
//    idle = { SDL_Texture1 },
//    shoot = { SDL_Texture1, SDL_Texture2 }
//};

//void Animator::ChangeSequence(Animations animationSequence){
//    sequenceVector = animationsVector[animationSequence];
//}
//
int Animator::animationSpeed = 500;

Animator::Animator(){
    sourceRectanglePointer = new SDL_Rect;
}

void Animator::ChangeSequence(int animationSequence, int framesCount){
    texturePointer = textures[animationSequence];
    this->framesCount = framesCount;
    sourceRectanglePointer->x = 0;
}

void Animator::ChangeFrame(){
    if(framesCount > 1)
        sourceRectanglePointer->x = sourceRectanglePointer->w * ((SDL_GetTicks() / animationSpeed) % framesCount);
}
