#ifndef Texte_H
#define Texte_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
typedef struct {
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface *surfaceTexte;
	SDL_Color textColor;
	char texte[50];
}Text;

void initText(Text *t);
void freeText(Text t);
void displayText(Text t,SDL_Surface *screen);

#endif

