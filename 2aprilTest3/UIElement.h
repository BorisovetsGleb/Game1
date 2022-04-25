#ifndef UIELEMENT_H_INCLUDED
#define UIELEMENT_H_INCLUDED

#include "Libraries.h"
#include "Object.h"
#include "Animator.h"

class UIELement : public Object, public Animator{
public:
    UIELement(int x, int y, int width, int height);
};

#endif // UIELEMENT_H_INCLUDED
