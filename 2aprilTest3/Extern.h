#ifndef EXTERN_H_INCLUDED
#define EXTERN_H_INCLUDED

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern vector<SDL_Texture*> textures;
extern vector<SDL_Surface*> sprites;
extern int *numberKeysPressed;//number of keys pressed
extern const Uint8* keyboardKeysPressed;//array of keys pressed


#endif // EXTERN_H_INCLUDED
