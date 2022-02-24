#include  "option.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


void option(int *continuersm,int * continuer,SDL_Surface * screen,int *screen_w,int *screen_h)
{
SDL_Event  event;
SDL_Rect pos_sm,pos_soundp,pos_soundm,pos_help;
SDL_Surface *image_sm=NULL,*image_soundm=NULL,*image_soundp=NULL,*image_help=NULL;

Mix_Music *music=NULL;
int channel,volume=100;
volume=Mix_Volume( channel, volume);
Mix_VolumeMusic(volume);  
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
               
music=Mix_LoadMUS("/home/nouur/menu/sonC.mp3");                 
Mix_PlayMusic(music,-1); 
Mix_Chunk *sound=NULL; 


image_sm=IMG_Load("/home/nouur/menu/backSM.png");

image_soundp=IMG_Load("/home/nouur/menu/sound+++.png");
pos_soundp.x=500;
pos_soundp.y=300; 
   
   
image_soundm=IMG_Load("/home/nouur/menu/sound---.png");
pos_soundm.x=300;
pos_soundm.y=300;  
image_help=IMG_Load("/home/nouur/menu/help.png");
pos_help.x=330;
pos_help.y=450;  
   

 
sound=Mix_LoadWAV("/home/nouur/menu/Menu_resources_sound1.wav");

  if(*continuersm==1)
{
while(*continuersm==1)
{    
   
 
 
  while(SDL_PollEvent(&event)) 
 {
 switch(event.type ) 
   { 
   case SDL_QUIT:  
   *continuersm=0;
   *continuer=0;
    break;
   
   case SDL_KEYDOWN:  
     switch(event.key.keysym.sym)
     {
     
       case SDLK_ESCAPE :
       case SDLK_q: 
         *continuersm=0;  
         
	  Mix_PlayChannel(-1,sound,0);
       break ;
    

           //volume up
      case SDLK_KP_PLUS : 
        if (volume < 100 )
          {
            volume += 20;
            Mix_VolumeMusic(volume);
          
            Mix_Volume( channel, volume);
	    
          }
           break;
            
      case SDLK_KP_MINUS : 
        if (volume >0 )
           {
            volume -= 20;
            Mix_VolumeMusic(volume);
          
            Mix_Volume( channel, volume);
                    
           }
           
            break;
     } 
       break; 
       
       
       case SDL_MOUSEBUTTONUP:
      if (event.button.button == SDL_BUTTON_LEFT && ( event.motion.x>pos_soundp.x && event.motion.x<pos_soundp.x+pos_soundp.w && event.motion.y>pos_soundp.y && event.motion.y<pos_soundp.y+pos_soundp.h ) ) 
         {
          if (volume < 100 )
          {
            volume += 20;
            Mix_VolumeMusic(volume);
     
            Mix_Volume( channel, volume);
	    Mix_PlayChannel(-1,sound,0);
          }
         }
     
       else if ( event.button.button == SDL_BUTTON_LEFT &&  ( event.motion.x>pos_soundm.x && event.motion.x<pos_soundm.x+pos_soundm.w &&     event.motion.y>pos_soundm.y && event.motion.y<pos_soundm.y+pos_soundm.h ) )
       
       {
          if (volume >0 )
           {
		Mix_PlayChannel(-1,sound,0);
            volume -= 20;
            Mix_VolumeMusic(volume);
   
            Mix_Volume( channel, volume);
            Mix_PlayChannel(-1,sound,0);         
           }
           
           
       }
       
       
       break;
     
   }
 }
 
       
    pos_sm.x=280;
    pos_sm.y=280;
    SDL_BlitSurface(image_sm,NULL,screen,&pos_sm);
    
	SDL_BlitSurface(image_help,NULL,screen,&pos_help);
    
    SDL_BlitSurface(image_soundp,NULL,screen,&pos_soundp);
          

    SDL_BlitSurface(image_soundm,NULL,screen,&pos_soundm); 
                
     SDL_Flip(screen); 
    
}

}




}//end channel
