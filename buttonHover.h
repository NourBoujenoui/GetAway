#ifndef buttonHover_H
#define buttonHover_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

 struct buttonH {
	SDL_Rect pos_playH,pos_optionH,pos_quitH;
        SDL_Surface *button_playH,*button_optionH,*button_quitH;
	
	
};
typedef struct buttonH buttonH;

void initButtonH(buttonH *BH);
void afficherPlay(buttonH BH,SDL_Surface *screen);
void afficherOption(buttonH BH,SDL_Surface *screen);
void afficherQuit(buttonH BH,SDL_Surface *screen);
void libererBH(buttonH BH);

#endif
