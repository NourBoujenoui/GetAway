#include "background.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>


void initBackground(Image *Backg)
{
Backg->img = IMG_Load("/home/nouur/menu/whattatata by mr.png");
if(Backg->img==NULL)
{printf("Unable to load : %s",SDL_GetError());
}
Backg->pos1.x=0;
Backg->pos1.y=0;
Backg->pos2.x=0;
Backg->pos2.y=0;
Backg->pos2.w=1200;
Backg->pos2.h=800;
}
void afficher(Image Backg,SDL_Surface *screen)
{
SDL_BlitSurface(Backg.img,NULL,screen,&Backg.pos1);
}
void liberer(Image Backg)
{
SDL_FreeSurface(Backg.img);
}
