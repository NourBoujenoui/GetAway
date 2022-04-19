#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>

#include <SDL/SDL_image.h>
#include "enigme.h"

void init_enigme(enigme * e,char nomfichier[])
{

	e->p.x=0;//plein écran
	e->p.y=0;	
	e->img=NULL;
FILE *f=NULL;
f=fopen("image","r");
if(f!=NULL){

while(fscanf(f,"%s %s %s %s\n",e->image1,e->image2,e->image3,e->image4)!=EOF)

fclose(f);
}

printf(" %s  %s %s %s\n",e->image1,e->image2,e->image3,e->image4);
}






 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
	int test=*alea ;
do{
 *alea = 1+ rand()%4;//1,2,3,4
}while(*alea==test) ;//le nombre aléa obtenu

 sprintf(image ,"%d.jpg",*alea);   // convertion en chaine de caractere
 e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen);
}


void afficher_chrono(enigme *en,SDL_Surface *screen,int i ) 
{ 
SDL_Surface *img=NULL;
SDL_Rect pos;

                pos.x=300;
                pos.y=-20;

             
		

	
          
           
             switch ( i )
		{
		case 0:	
		en->img = IMG_Load("timer0.png");	
		break;

		case 1:
		en->img = IMG_Load("timer1.png");
		break;

		case 2:	
		en->img = IMG_Load("timer2.png");       
		break;

		case 3:		
		en->img = IMG_Load("timer3.png");	
		break;

		case 4:		
		en->img = IMG_Load("timer4.png"); 		
		break;

		case 5:		
		en->img = IMG_Load("timer5.png");		
		break;

		case 6:
		en->img = IMG_Load("timer6.png");
		break;

		case 7:		
		en->img = IMG_Load("timer7.png"); 		
		break;

                case 8:		
		en->img = IMG_Load("timer8.png"); 		
		break;

		case 9:		
		en->img = IMG_Load("timer9.png");  		
		break;

		case 10:		
		en->img = IMG_Load("timer10.png");  		
		break;


                case 11:		
		en->img = IMG_Load("timer11.png");
		break;
		

}


	SDL_Flip(screen);
	SDL_BlitSurface(en->img, NULL, screen, &pos) ;



	
   /*  if (i==12){SDL_FreeSurface(en->img);
		en->img = IMG_Load("img/youlost.png");
  		SDL_BlitSurface(en->img, NULL, screen, &post) ;}
	*/

	//SDL_Delay(750);	
        
 	
     

}

 void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en)
 {
         SDL_Rect pos;
          pos.x=250;
          pos.y=570; 


	SDL_Rect pos_passfail;
        pos_passfail.x=0;
        pos_passfail.y=0; 

	SDL_Surface *pass=IMG_Load("pass.jpg");	
	SDL_Surface *fail=IMG_Load("failed.jpg");	



 	if (r==s)    //si la réponse est juste(déja connu maintenant)
 	{
	SDL_BlitSurface(pass, NULL, screen,&pos_passfail) ;
		


       for (int j=0;j<=5;j++){
                 switch(j){
		case 1 :
                en->img=IMG_Load("p1.png");
              
 		SDL_BlitSurface(en->img, NULL, screen,&pos) ;
                break;
                case 2: 
                  en->img=IMG_Load("p1.png");
              
 		SDL_BlitSurface(en->img, NULL, screen,&pos) ;
                break;
                case 3: 
                  en->img=IMG_Load("p2.png");
              
 		SDL_BlitSurface(en->img, NULL, screen,&pos) ;
                break;
                 case 4: 
                  en->img=IMG_Load("p2.png");
              
 		SDL_BlitSurface(en->img, NULL, screen,&pos) ;
                break;
       		 }
          SDL_Delay(50);
         SDL_Flip(screen);
      
 	}

       }

	else if ((r!=s)&&(r!=0))
		SDL_BlitSurface(fail, NULL, screen,&pos_passfail) ;

 }



void animer (enigme *e)
{
		e->num_animation++;
		if(e->num_animation==12)
                {
			e->num_animation=0;
			e->time_over=1;	
		}	
SDL_Delay(250);
}
