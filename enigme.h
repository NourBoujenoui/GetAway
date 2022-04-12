#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>



typedef struct enigme
{
char question[100];
char reponse1[100];
char reponse2[100];
char reponse3[100];
int reponse;


SDL_Surface *surfacequestion;
SDL_Surface *surfacereponse1;
SDL_Surface *surfacereponse2;
SDL_Surface *surfacereponse3;

SDL_Rect positionquestion;
SDL_Rect positionreponse1;
SDL_Rect positionreponse2;
SDL_Rect positionreponse3;

}enigme;

void afficherenigme(enigme e,SDL_Surface *screen);
void init_enigmes(enigme *e);
void animer(enigme *e,SDL_Rect *pos_sprite,int j);

//int charger(personne *p,background *b,char *nomfichier);
//void sauvegarder(personne p,background b,char *nomfichier);


