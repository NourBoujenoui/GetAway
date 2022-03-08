
#ifndef entiteSecondaire_H_
#define entiteSecondaire_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

void initEnnemi(Ennemi*e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e);
int collisionBB( personne p, Ennemi e);
void deplacerIA( Ennemi * e, SDL_Rect posPerso);



#endif


