#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Libraries.h"
#include "Object.h"
#include "Extern.h"

class Menu : public Object
{
public:
	Menu();
	bool Out(bool IsTupped);

private:
	//SDL_Event event;
	bool* InMenu;
};

#endif // MENU_H_INCLUDED