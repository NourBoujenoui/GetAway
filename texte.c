#include <SDL/SDL.h>
#include "texte.h"
#include <SDL/SDL_image.h>


void initText(Text *t)
{	

	t->position.x=400;
	t->position.y=150;	
//couleur blanc
 	t->textColor.r=255;
	t->textColor.g=255;
	t->textColor.b=255;
	
	t->font = TTF_OpenFont( "BigwogsGTDemo.ttf", 70 );
}


void displayText(Text t,SDL_Surface *screen)
{
t.surfaceTexte = TTF_RenderText_Blended(t.font, "M E N U", t.textColor );
	SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
}
void freeText(Text t)
{
	SDL_FreeSurface(t.surfaceTexte);
}
