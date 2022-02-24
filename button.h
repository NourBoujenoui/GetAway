#ifndef button_H
#define button_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

 struct button {
	SDL_Rect pos_play,pos_option,pos_quit;
        SDL_Surface *button_play,*button_option,*button_quit;
	
	
};
typedef struct button button;

void initButton(button *B);
void afficherButton(button B,SDL_Surface *screen);
void libererB(button B);

#endif
