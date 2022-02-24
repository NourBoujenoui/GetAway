#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "jouer.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


void jouer(int *continuerj ,int *continuer, SDL_Surface *screen)
{


SDL_Surface * image_game;



SDL_Event  event;

image_game=IMG_Load("/home/nouur/menu/Loading.jpg");
 if(*continuerj==1)
{
while(*continuerj==1)
{
 
       
    while(SDL_PollEvent(&event)) 
 {
 switch(event.type ) 
   { 
   case SDL_QUIT:  
      *continuerj=0;
      *continuer=0;
       break;
       
   case SDL_KEYDOWN:  
     switch(event.key.keysym.sym)
     {
       
       case SDLK_q: 
         *continuerj=0;   
         
	  
       break ;
     } 
       break; 
               
   }

 }






  
    SDL_BlitSurface(image_game,NULL,screen,NULL);
    SDL_Flip(screen); 
}
}

}
