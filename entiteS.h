#ifndef entiteS_H
#define entiteS_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ennemi{
	SDL_Rect posPerso;
        SDL_Surface *img_ennemi;
}e;

void initEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi *e);
void deplacer( Ennemi *e);
int collisionBB( personne p, Ennemi e);
void deplacerIA( Ennemi *e, SDL_Rect posPerso);



#endif
