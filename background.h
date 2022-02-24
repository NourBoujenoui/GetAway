#ifndef background_H
#define background_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Image{
	SDL_Rect pos1,pos2;
        SDL_Surface *img;
}Image;


void initBackground(Image *Backg);
void afficher(Image Backg,SDL_Surface *screen);
void liberer(Image Backg);

#endif
