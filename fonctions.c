#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"
void initPerso(Personne *p)
{
p->tab[0]=IMG_Load("/home/omar/Bureau/perso/pers2.png");
p->tab[1]=IMG_Load("/home/omar/Bureau/perso/perso5.png");
p->tab[2]=IMG_Load("/home/omar/Bureau/perso/pers1.png");
p->i=0;
p->tab[3]=IMG_Load("/home/omar/Bureau/perso/1500x800-px-colorful-galaxy-space-space-art-stars-1060468-wallhere.com.png");
p->sc=IMG_Load("");
p->up=0;
p->vitesse=5;
p->acc=0;
p->positionperso.x=200;
p->positionperso.y=200;
p->positionperso.w=p->tab[0]->w;
p->positionperso.h=p->tab[0]->h;
}
void afficherPerso(Personne p, SDL_Surface * screen)
{

SDL_Rect positionbakground;
SDL_Rect positionscore;

positionbakground.x=0;
positionbakground.y=0;
positionscore.x=1200;
positionscore.y=-100;

SDL_BlitSurface(p.tab[3], NULL, screen, &positionbakground);
SDL_BlitSurface(p.tab[(p.i)], NULL,screen,&p.positionperso);
SDL_BlitSurface(p.sc,NULL,screen,&positionscore);

}
void animerPerso (Personne* p)
{
(p->i)++;
if((p->i)>2)
p->i=0;
}
void deplacerPerso (Personne *p,Uint32 dt)
{

SDL_Event event1;
SDL_PollEvent(&event1);
switch(event1.type)
{
case SDL_KEYDOWN:
switch(event1.key.keysym.sym)
{
case SDLK_d:
p->positionperso.x+=(p->acc)*dt*dt+(p->vitesse)*dt;
animerPerso(p);
p->acc-=0.001;

break;
case SDLK_q:
p->positionperso.x-=(p->acc)*dt*dt+(p->vitesse)*dt;
animerPerso(p);
p->acc-=0.001;
break;
case SDLK_z:
p->positionperso.y-=(p->acc)*dt*dt+(p->vitesse)*dt;
animerPerso(p);
p->acc-=0.001;
break;
case SDLK_s:
p->positionperso.y+=(p->acc)*dt*dt+(p->vitesse)*dt;
animerPerso(p);
p->acc-=0.001;
break;
case SDLK_LSHIFT:
p->acc+=0.005;
break;
}
break;

}


}
void saut (Personne* p,int dt, int posinit) 
{

SDL_Event event1;
SDL_PollEvent(&event1);
switch(event1.type)
{
case SDL_KEYDOWN:
switch(event1.key.keysym.sym)
{
case SDLK_SPACE:
p->positionperso.x=p->positionperso.x+(p->acc)*dt*dt+(p->vitesse)*dt;
p->positionperso.y=p->positionperso.y-200;
break;
}
break;
SDL_Delay(0.2);
case SDL_KEYUP:
switch(event1.key.keysym.sym)
{
case SDLK_SPACE:

p->positionperso.y=posinit;
p->positionperso.x+=(p->acc)*dt*dt+(p->vitesse)*dt;
break;
}

break;

}




}
















