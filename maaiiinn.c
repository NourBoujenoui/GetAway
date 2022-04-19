#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include <time.h>

int main()
{

	 SDL_Surface *screen;
	 enigme  e;
	 int run =1,running=1,alea,detect=0;
	 int s,r;
	 char image[30]="";
	 SDL_Event event;
    	 srand(time(NULL));        //obtenir un nombre aléa a chaque reprise
         int i=0;
	 SDL_Init ( SDL_INIT_VIDEO ) ;
	 screen=SDL_SetVideoMode(564,772,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
	 init_enigme(&e,"image");
         generate_afficher ( screen  , image ,&e,&alea) ;
	 //s=solution_e(image);
	 r=0;
	 int bt_next=0;
	 while (run)
	 {  
	   
	  SDL_PollEvent(&event);
	
int s=0 ;
 	if(strcmp(image,"1.jpg")==0) 
 	{
     	s =2 ;
 	}
 	else  	if(strcmp(image,"2.jpg")==0)
 	{
 		s =2;

 	}
 	else 	if(strcmp(image,"3.jpg")==0)
 	{
 		s=1;	
 	}
        else 	if(strcmp(image,"4.jpg")==0)
 	{
 		s =1;	
 	}

           switch(event.type)
            {
		 case SDL_KEYDOWN : 
            		switch( event.key.keysym.sym )
                {
			case SDLK_q:
                        run = 0;
			  break ;
			  case SDLK_a: //touche a réponse1
		        
                          {
			  r=1; 
			  afficher_resultat (screen,s,r,&e) ;
			  bt_next=1;
                          }
			  break ;
			  case SDLK_b://touche b réponse2 
			  {
			  r=2;
			  afficher_resultat (screen,s,r,&e) ;
			  bt_next=1;
                          }
			  break;
			  case SDLK_c: //touche c réponse3
			
                          {
			  r=3 ;
		 	  afficher_resultat (screen,s,r,&e) ;
			  bt_next=1;
			  }
			  break;

			  case SDLK_ESCAPE: 
			  bt_next=0;
			  r=0;
			  i=0;
			  generate_afficher ( screen , image ,&e,&alea) ;
			  break;



				 } 


 






		 case SDL_MOUSEBUTTONDOWN:
		{

 switch(event.button.button){
	 case SDL_BUTTON_LEFT:

	{

           
 if(event.button.x>110 && event.button.x<300 && event.button.y>350 && event.button.y<430)// position question
            {
	if(bt_next==0){
			  r=1; 
			  afficher_resultat (screen,s,r,&e) ;
			  bt_next=1;}
			}
           

          
	else if(event.button.x>110 && event.button.x<300 && event.button.y>450 && event.button.y<500)//reponse 1
            {
               if(bt_next==0){
			  r=2;
			  afficher_resultat (screen,s,r,&e) ;
			  bt_next=1;}
			            }


	else if(event.button.x>110 && event.button.x<300 && event.button.y>520 && event.button.y<580)//reponse2
            {        
    if(bt_next==0){
			  r=3 ;
		 	  afficher_resultat (screen,s,r,&e) ;
			  bt_next=1;
			  }
  	}
			









	}

	}


}
	//case SDL_MOUSEMOTION:

	//printf("x:%d y:%d\n",event.motion.x,event.motion.y);  ///cordonnes de la souris

				 }                                           
      
 if(r==0)
            i++;  
	    running=1;
	    SDL_Flip(screen);
if(i==600)
       {
r=-1;
	
	}

afficher_resultat (screen,s,r,&e) ;
if(i%50==0)
afficher_chrono(&e,screen,i/50);	
SDL_Delay(10);	
  }   //while lkbira

      SDL_FreeSurface(screen);   //libérer l'espace de mémoire utilisé
      SDL_Quit();
	return 0;
}
