#ifndef back_H_INCLUDED
#define back_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct background
	{
        SDL_Surface *image;
				SDL_Surface * mask;
        SDL_Rect camera;
        Mix_Music *music;
    }background;

void initBack(background * b);
void aficherBack(background b, SDL_Surface * screen);
void scrolling (background * b, int direction, int pasAvancement );

/*SDL_Color GetPixel(SDL_Surface *pSurface , int x,int y);
int collision_parfaite_right(SDL_Surface *mask , SDL_Rect posjoueur,SDL_Rect camera );
int collision_parfaite_left(SDL_Surface *mask , SDL_Rect posjoueur ,SDL_Rect camera);
int collision_parfaite_up(SDL_Surface *mask , SDL_Rect posjoueur ,SDL_Rect camera);
int collision_parfaite_down(SDL_Surface *mask , SDL_Rect posjoueur ,SDL_Rect camera);*/



#endif // DS_H_INCLUDED
