#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"
int main() {
Personne p;


int col;
int cont=1;
int c;
SDL_Init(SDL_INIT_VIDEO);
Uint32 dt, t_prev;
SDL_Surface *screen=NULL;
SDL_Event event;

initPerso(&p);

screen = SDL_SetVideoMode(1600,1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);


SDL_Flip(screen);
SDL_EnableKeyRepeat(100,100);
while(cont)
{
t_prev=SDL_GetTicks();    
SDL_PollEvent(&event);
if(event.type==SDL_QUIT)
cont=0;
switch(event.type)
{
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_o:
cont=0;

break;
}
}
afficherPerso(p,screen);

deplacerPerso (&p,dt);
c=p.positionperso.y;
saut(&p,dt,200);





SDL_Flip(screen);





dt=SDL_GetTicks()-t_prev;    
}
SDL_FreeSurface(screen);
}
