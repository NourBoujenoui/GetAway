#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include "enigme.c"
#include <string.h>




//// gcc enigme_main.c -o pr0 -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 

	                	
int score=100;

char scorechar[100];// score"chaine"




int main(){

TTF_Init();

TTF_Font*police=NULL;

TTF_Font*policee=NULL;

SDL_Color red={125,0,0};
SDL_Color white={0,0,0};////black
police=TTF_OpenFont("Trajan Pro.ttf",20);
policee=TTF_OpenFont("Trajan Pro.ttf",15);


Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
Mix_Chunk* soundbtn;
soundbtn = Mix_LoadWAV("mixkit-game-click-1114.wav");





///score

SDL_Surface *surface_score=NULL;

SDL_Color blue={0,0,155};
SDL_Color green={0,200,0};

surface_score=TTF_RenderText_Blended(police,"score :",blue);
SDL_Rect position_score; 

position_score.x=50;
position_score.y=80;


////// you won /wrong
SDL_Surface *surface_message=NULL;
surface_message=TTF_RenderText_Blended(police,"",green);
SDL_Rect position_message; 
position_message.x=350;
position_message.y=200;





sprintf(scorechar,"%d",score);//convertir entier l chaine de charactere
SDL_Surface *surface_total_score=NULL;//surface score
surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);//valeur fl blue taa score
SDL_Rect position_total_score;
////position  score 
position_total_score.x=150;
position_total_score.y=80;








 

SDL_Surface *screen=NULL;


if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("erreur: %s \n",SDL_GetError());
return 1;
}



screen=SDL_SetVideoMode(500,314,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen==NULL)
{
printf("unable to set video mode :%s",SDL_GetError());
return 1;
}




SDL_Surface *image=NULL;
image=IMG_Load("image1.jpg");

SDL_Rect position; 
position.x=0;
position.y=0;




enigme e;
init_enigmes(&e);



int cont=1;//quitter

SDL_Event event;




int detect_sound=0;//tet7arek bl souris 

int detect_reponse=0;///pour detecter reponse juste ou fausse





//////////animation

SDL_Surface *skull=NULL;

skull=IMG_Load("skulltest.png");




SDL_Rect pos_sprite;
SDL_Rect pos_screen;

pos_sprite.x=0;
pos_sprite.y=0;
pos_sprite.w=785/9;
pos_sprite.h=175/2;


 
pos_screen.x=390;
pos_screen.y=210;




////bouton next

SDL_Surface *btnext=NULL;

btnext=IMG_Load("boutonnext.jpg");
SDL_Rect position_btnext; 
position_btnext.x=455;
position_btnext.y=250;




SDL_Surface *surface_texte=NULL;
surface_texte=TTF_RenderText_Blended(policee,"le premier paragraphe  a afficher",white);
SDL_Rect position_texte; 
position_texte.x=30;
position_texte.y=30;


int click=0;//lel bouton


////////////////////////////////////////


while(cont==1){
	if(score<=0)
	cont=0;////
	
	SDL_BlitSurface(image,NULL,screen,&position);
	if(click<2){
	SDL_BlitSurface(btnext,NULL,screen,&position_btnext);
	SDL_BlitSurface(surface_texte,NULL,screen,&position_texte); 
}
	if(click>=2){
		
	image=IMG_Load("13847715.jpg");
	SDL_BlitSurface(surface_total_score,NULL,screen,&position_total_score);
	SDL_BlitSurface(surface_score,NULL,screen,&position_score);
	afficherenigme(e,screen);

}





        SDL_PollEvent(&event);

        switch(event.type)
        {
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE://pour quitter
                cont=0;
                break;

	    case SDLK_a:
            {
		if(detect_reponse==0){
			if(e.reponse!=1){
				score-=20;
				init_enigmes(&e);//nt3ada lli ba3do 
				sprintf(scorechar,"%d",score);
				surface_message=TTF_RenderText_Blended(policee,"Wrong!",red);	
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
					
				pos_sprite.x=0;
				pos_sprite.y=0;
				
		/////animation
		for(int i=0;i<2;i++){
			for(int j=0;j<9;j++){
				SDL_Flip(screen);
				animer(&e,&pos_sprite,j);
				SDL_BlitSurface(skull,&pos_sprite,screen,&pos_screen);
				SDL_Flip(screen);
				SDL_Delay(100);
				SDL_BlitSurface(surface_message,NULL,screen,&position_message);
				SDL_Flip(screen);}

				pos_sprite.x=0;
				pos_sprite.y+=pos_sprite.h;}////passer a la ligne suivante
				surface_message=TTF_RenderText_Blended(policee,"",red);	///// fin annimation nn l msg taa wrong
				}

			else if(e.reponse==1){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);	
				detect_reponse=1;
				surface_message=TTF_RenderText_Blended(policee,"You Won",green);
				}}
										}break;





            case SDLK_b:

            {	
		if(detect_reponse==0){
			if(e.reponse!=2){
				score-=20;
				init_enigmes(&e);
				detect_reponse=0;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				surface_message=TTF_RenderText_Blended(policee,"Wrong!",red);
				pos_sprite.x=0;
				pos_sprite.y=0;
		for(int i=0;i<2;i++){
			for(int j=0;j<9;j++){
						SDL_Flip(screen);
						animer(&e,&pos_sprite,j);
						SDL_BlitSurface(skull,&pos_sprite,screen,&pos_screen);
						SDL_BlitSurface(surface_message,NULL,screen,&position_message);
						SDL_Flip(screen);
						SDL_Delay(100);
						SDL_Flip(screen);}
				pos_sprite.x=0;
				pos_sprite.y+=pos_sprite.h;}
				surface_message=TTF_RenderText_Blended(policee,"",red);	
				}
				else if(e.reponse==2){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				detect_reponse=1;
				surface_message=TTF_RenderText_Blended(policee,"You Won",green);}}
		

		}
		break;
 

		case SDLK_c:
            {	
		if(detect_reponse==0){
			if(e.reponse!=3){
				score-=20;	
				detect_reponse=0;			
				init_enigmes(&e);
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				surface_message=TTF_RenderText_Blended(policee,"Wrong !",red);
				pos_sprite.x=0;
				pos_sprite.y=0;
for(int i=0;i<2;i++){
		for(int j=0;j<9;j++){
				SDL_Flip(screen);
				animer(&e,&pos_sprite,j);
				SDL_BlitSurface(skull,&pos_sprite,screen,&pos_screen);
				SDL_BlitSurface(surface_message,NULL,screen,&position_message);
				SDL_Flip(screen);
				SDL_Delay(100);
				SDL_Flip(screen);}
				pos_sprite.x=0;
				pos_sprite.y+=pos_sprite.h;
				}
				surface_message=TTF_RenderText_Blended(policee,"",red);	
				}
			else if(e.reponse==3){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				detect_reponse=1;surface_message=TTF_RenderText_Blended(policee,"You Won",green);
				}}}
				break;}
	

	
case SDL_MOUSEBUTTONDOWN:
        {
            switch(event.button.button)
            {
            case SDL_BUTTON_LEFT:

            {
                  if(event.button.x>400 && event.button.x<450 && event.button.y>50 && event.button.y<70)
            {
		if(detect_reponse==0){
				if(e.reponse!=1){
				score-=20;
				init_enigmes(&e);
				
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				surface_message=TTF_RenderText_Blended(policee,"Wrong!",red);
				pos_sprite.x=0;
				pos_sprite.y=0;
		for(int i=0;i<2;i++){
				for(int j=0;j<9;j++){
						SDL_Flip(screen);
						animer(&e,&pos_sprite,j);
						SDL_BlitSurface(skull,&pos_sprite,screen,&pos_screen);
						SDL_BlitSurface(surface_message,NULL,screen,&position_message);
						SDL_Flip(screen);
						SDL_Delay(100);
						SDL_Flip(screen);}
				pos_sprite.x=0;
				pos_sprite.y+=pos_sprite.h;}
	surface_message=TTF_RenderText_Blended(policee,"",red);	
				}
			else if(e.reponse==1){
				score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);	
				detect_reponse=1;
				surface_message=TTF_RenderText_Blended(policee,"You Won",green);
				}
		}}

		else if(event.button.x>400 && event.button.x<450 && event.button.y>100 && event.button.y<120)
            {        
       		
		if(detect_reponse==0){
			if(e.reponse!=2){
				score-=20;
				init_enigmes(&e);
				
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				surface_message=TTF_RenderText_Blended(policee,"Wrong!",red);
				pos_sprite.x=0;
				pos_sprite.y=0;
		for(int i=0;i<2;i++){
				for(int j=0;j<9;j++){
						SDL_Flip(screen);
						animer(&e,&pos_sprite,j);
						SDL_BlitSurface(skull,&pos_sprite,screen,&pos_screen);
						SDL_BlitSurface(surface_message,NULL,screen,&position_message);
						SDL_Flip(screen);
						SDL_Delay(100);
						SDL_Flip(screen);}
				pos_sprite.x=0;
				pos_sprite.y+=pos_sprite.h;}
	surface_message=TTF_RenderText_Blended(policee,"",red);	
				}
				else if(e.reponse==2){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				detect_reponse=1;surface_message=TTF_RenderText_Blended(policee,"You Won",green);
				}
		
		
		}
            }

		else if(event.button.x>400 && event.button.x<450 && event.button.y>150 && event.button.y<170)
            {
       
		if(detect_reponse==0){
			if(e.reponse!=3){
				score-=20;
				init_enigmes(&e);
				detect_reponse=0;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				surface_message=TTF_RenderText_Blended(policee,"Wrong!",red);
				pos_sprite.x=0;
				pos_sprite.y=0;
		for(int i=0;i<2;i++){
				for(int j=0;j<9;j++){
						SDL_Flip(screen);
						animer(&e,&pos_sprite,j);
						SDL_BlitSurface(skull,&pos_sprite,screen,&pos_screen);
						SDL_BlitSurface(surface_message,NULL,screen,&position_message);
						SDL_Flip(screen);
						SDL_Delay(100);
						SDL_Flip(screen);}
				pos_sprite.x=0;
				pos_sprite.y+=pos_sprite.h;}
	surface_message=TTF_RenderText_Blended(policee,"",red);	
				

					}



			else if(e.reponse==3){score+=20;
				sprintf(scorechar,"%d",score);
				surface_total_score=TTF_RenderText_Blended(police,scorechar,blue);
				detect_reponse=1;surface_message=TTF_RenderText_Blended(policee,"You Won",green);}
		}

	
		 }

		
		


		

///////////////////boutonnext


		else if(event.button.x>455 && event.button.x<500 && event.button.y>250 && event.button.y<270)
            {
       
			click++;
			SDL_Delay(500);
			surface_texte=TTF_RenderText_Blended(policee,"le deuxieme paragraphe  a afficher",white);
			
	

	
		 }



        }//case

}
}

 case SDL_MOUSEMOTION:
        {
	//printf("x:%d y:%d\n",event.motion.x,event.motion.y);
         if(event.motion.x>50 && event.motion.x<150 && event.motion.y>20 && event.motion.y<40)// postion question
            {
	if(detect_sound==0){
           	Mix_PlayChannel(-1,soundbtn,0 );
		detect_sound=1;

}
           

          }
	else if(event.motion.x>400 && event.motion.x<450 && event.motion.y>50 && event.motion.y<70)//reponse 1
            {
               if(detect_sound==0){
           	Mix_PlayChannel(-1,soundbtn,0);
		detect_sound=1;	
		e.surfacereponse1=TTF_RenderText_Blended(police,e.reponse1,red);
		e.surfacereponse2=TTF_RenderText_Blended(police,e.reponse2,white);
		e.surfacereponse3=TTF_RenderText_Blended(police,e.reponse3,white);}
            }


	else if(event.motion.x>400 && event.motion.x<450 && event.motion.y>100 && event.motion.y<120)//reponse2
            {        
       	if(detect_sound==0){
           	Mix_PlayChannel(-1,soundbtn,0 );
		detect_sound=1;}
	e.surfacereponse1=TTF_RenderText_Blended(police,e.reponse1,white);
        e.surfacereponse2=TTF_RenderText_Blended(police,e.reponse2,red);			
	e.surfacereponse3=TTF_RenderText_Blended(police,e.reponse3,white);
            }


	else if(event.motion.x>400 && event.motion.x<450 && event.motion.y>150 && event.motion.y<170)
            {    
       	if(detect_sound==0){
           	Mix_PlayChannel(-1,soundbtn,0 );
		detect_sound=1;}
	e.surfacereponse3=TTF_RenderText_Blended(police,e.reponse3,red);
        e.surfacereponse1=TTF_RenderText_Blended(police,e.reponse1,white);
	e.surfacereponse2=TTF_RenderText_Blended(police,e.reponse2,white);     
            }
	else{
	detect_sound=0;
	e.surfacereponse3=TTF_RenderText_Blended(police,e.reponse3,white);
        e.surfacereponse1=TTF_RenderText_Blended(police,e.reponse1,white);
	e.surfacereponse2=TTF_RenderText_Blended(police,e.reponse2,white);}
	   
              
	    
}
    


}

SDL_Flip(screen);

if(click>=2){
SDL_BlitSurface(surface_total_score,NULL,screen,&position_total_score);//postion mtaa score
SDL_BlitSurface(surface_score,NULL,screen,&position_score);//position score char 
SDL_BlitSurface(surface_message,NULL,screen,&position_message);//position message (wrong you won )
SDL_Flip(screen);
SDL_Delay(20);

}
}

SDL_Quit();

return 0;}





