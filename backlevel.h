#ifndef backlevel_H
#define backlevel_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#define SCREEN_W 1400
#define SCREEN_H 600
typedef struct {
	SDL_Rect pos1,pos2;
        SDL_Surface *img;
}Image;


void initBacklevel(Image *Backg);

void afficher(Image Backg,SDL_Surface *screen);

#endif
