#ifndef enigme_H
#define enigme_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
char quest[100],R1[10],R2[10],R3[10];
int i;
SDL_Surface * img;
SDL_Rect p;

}enigme;



void initEnigme(enigme * e,char *nomfichier);
void afficherEnigme(enigme e,SDL_Surface * screen);
enigme generer(char * nomfichier);
void animer(enigme * e);
#endif
