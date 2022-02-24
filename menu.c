#include "background.h"
#include "button.h"
#include "buttonHover.h"
#include "texte.h"
#include "jouer.h"
#include "option.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

int main(int argc,char** argv)
{
 int continuer=1,continuerj=0,continuersm=0,move=6;

if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER )!=0) 
        {
           printf("Unable to initialize SDL : %s \n",SDL_GetError());
          return 1;
         }  
         
int screen_w=1200,screen_h=800;
SDL_Surface *screen=NULL;
SDL_WM_SetCaption("My Game Window",NULL);
screen=SDL_SetVideoMode( screen_w,screen_h,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

SDL_Event  event; // input events
Mix_Chunk *sound=NULL;
Mix_Music *music=NULL; 

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
               
music=Mix_LoadMUS("/home/nouur/menu/sonC.mp");                 
Mix_PlayMusic(music,-1);

//Background
Image Backg;
initBackground(&Backg);
//animation
SDL_Surface *image_animation=NULL;
SDL_Rect back;

image_animation=IMG_Load("/home/nouur/menu/assassasasa.png");

     
// text Menu

TTF_Init();
Text t;
initText(&t);
//button
button B;
initButton(&B);

//button Hover
buttonH BH;
initButtonH(&BH);
//son Disc

sound=Mix_LoadWAV("/home/nouur/menu/Menu_resources_sound1.wav");

// boucle menu principal 
while(continuer==1)
{

 
  

afficher(Backg,screen);
afficherButton(B,screen);
displayText(t,screen);
SDL_Flip(screen); 
   

while(SDL_PollEvent(&event)) 
 {
 switch(event.type) 
   { 
   case SDL_QUIT:  
      continuer=0;
       break;

   case SDL_KEYDOWN:  
     switch(event.key.keysym.sym)
     {
       case SDLK_ESCAPE : 
       case SDLK_q: // q for quit 
         continuer=0;   
       break ;
      
      case SDLK_p: //  for play 
      

	  Mix_PlayChannel(-1,sound,0);
 		jouer( &continuerj ,&continuer, screen);         
 		continuerj=1;
	   //appel de la fonction jouer
	  
      break;
      
      
      case SDLK_s:  // s for settings 
 
	  Mix_PlayChannel(-1,sound,0);
	   continuersm=1;
	  option(&continuersm,&continuer, screen, &screen_w, &screen_h);
	  
      break;
 case SDLK_f:
      SDL_WM_ToggleFullScreen( screen); //full screen
      break;
      
      
            case SDL_VIDEORESIZE:
               screen_w = 800;
               screen_h = 600;
               break;
      
     }
       break; 
 case SDL_MOUSEMOTION:  
    if (event.motion.x>120 && event.motion.x<220 && event.motion.y>150 && event.motion.y<200)
    {   
              afficherPlay(BH,screen);
		SDL_Flip(screen);


  
    }
      else if  ( event.motion.x>120 && event.motion.x<220 &&     event.motion.y>250 && event.motion.y<300)
    {
               afficherOption(BH,screen);
		SDL_Flip(screen);

		
   
    }       
    else if (   event.motion.x>120 && event.motion.x<220 && event.motion.y>300 && event.motion.y<350)
    {
              afficherQuit(BH,screen);
		SDL_Flip(screen);
		
    }
		

     break;
 case SDL_MOUSEBUTTONUP:
      if (event.button.button == SDL_BUTTON_LEFT && ( event.motion.x>120 && event.motion.x<220 && event.motion.y>150 && event.motion.y<200 ) ) 
         {   
 	       	
	       afficherPlay(BH,screen);
              jouer(&continuerj,&continuer, screen);
		continuerj=1;	
		SDL_Flip(screen);
		Mix_PlayChannel(-1,sound,0);
  
	
            
         }
     
       else if ( event.button.button == SDL_BUTTON_LEFT &&  ( event.motion.x>120 && event.motion.x<220 &&     event.motion.y>250 && event.motion.y<300 ) )
       
       {   
		
                afficherOption(BH,screen);
                
		
		option(&continuersm,&continuer, screen, &screen_w, &screen_h);
		continuersm=1;
		SDL_Flip(screen);
		Mix_PlayChannel(-1,sound,0);
	  
	  
          
       }
       
       else if ( event.button.button == SDL_BUTTON_LEFT && (event.motion.x>120  && event.motion.x<220  && event.motion.y>350 && event.motion.y<400) )
       {    
		
		afficherQuit(BH,screen);
		SDL_Flip(screen);
		Mix_PlayChannel(-1,sound,0); 
		continuer=0;

		
       }
       
       break;
}

}
back.y+= move;         
back.x=700; 
SDL_BlitSurface(image_animation,NULL,screen,&back);
if(back.y>600)
     {
      back.y= (-60);
      back.y+=move;
     } 
SDL_Flip(screen);

}


	

//Liberer Memoire


freeText(t);
TTF_CloseFont(t.font);
libererB(B);
libererBH(BH);
liberer(Backg);
Mix_FreeMusic(music);
Mix_FreeChunk(sound);

return 0;
}





