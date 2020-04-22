#include"enemy.h"
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include<time.h>


void initialiser_enemy(enemy* E)
{
    E->position_enemy.x = 400; //initialiser position de l'entité
    E->position_enemy.y = 440;
E->image_enemy[0] = IMG_Load("2.png"); //charger les images
E->image_enemy[1] = IMG_Load("3.png");
E->image_enemy[2] = IMG_Load("4.png");
E->image_enemy[3] = IMG_Load("5.png");
E->image_enemy[4] = IMG_Load("22.png");
E->image_enemy[5] = IMG_Load("33.png");
E->image_enemy[6] = IMG_Load("44.png");
E->image_enemy[7] = IMG_Load("55.png");
    //SDL_SetColorKey(E->image_enemy, SDL_SRCCOLORKEY, SDL_MapRGB(E->image_enemy->format, 0, 0, 255));
     E->positionmin_enemy.x=400; //position min choisi
  E->positionmax_enemy.x=0;

}






int position_aleatoire(int positionmax,int positionmin) //fct pour une valeur aleatoire
{
int pos;
srand(time(NULL));
pos=rand()%(positionmax-positionmin+1)+positionmin;

return pos;
}





void deplacement_aleatoire(enemy E,SDL_Surface *screen)
{
SDL_Event event;
SDL_Surface *back;
SDL_Rect posback;
int continuer = 1;
int tempsPrecedent = 0, tempsActuel = 0;
int i=0,j=3,droit=0,gauche=0;
int pos;
static int k=0;
    
posback.x=0;
posback.y=0;
back=IMG_Load("back.jpg");
E.positionmax_enemy.x=screen->w / 2 ;

pos=position_aleatoire(E.positionmax_enemy.x,E.positionmin_enemy.x);



    SDL_EnableKeyRepeat(10, 10);

    while (continuer)
    {

        SDL_PollEvent(&event); /* On utilise PollEvent et non WaitEvent pour ne pas bloquer le programme */
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        tempsActuel = SDL_GetTicks();



        if (tempsActuel - tempsPrecedent > 30) /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
        {
           
               if(k==0)// variable k pour savoir si on a atteint le max

                   {
                     if(E.position_enemy.x<pos)/*positionmax)*/
                          {
                            E.position_enemy.x=E.position_enemy.x+5;

SDL_Delay(50);
				i++;//compteur pour les images droit du l'entité
if(i==3)i=0;
droit=1;gauche=0;
				j=3;

                          }
                     else k=1;

                   }
              if(k==1)
                  {
                    if(E.position_enemy.x>E.positionmin_enemy.x)
{
                            E.position_enemy.x=E.position_enemy.x-5;
SDL_Delay(50);
			    i=0;
			    j++;//compteur pour les images gauche du l'entité
if(j==7)j=4;			    
gauche=1;droit=0;
}
                    else
                         k=0;
                  }             
                                    /* On bouge l'ennemi */
            tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
        }
	SDL_BlitSurface(back, NULL, screen, &posback);
	if(droit==1)SDL_BlitSurface(E.image_enemy[i], NULL, screen, &E.position_enemy);
	if(gauche==1)SDL_BlitSurface(E.image_enemy[j], NULL, screen, &E.position_enemy);
	
	   
        SDL_Flip(screen);//rafraichir l'ecran
    }

   
   

}

void freesurfaceennemi(enemy *ennemi)
{
int i;
for(i=0;i<7;i++)
SDL_FreeSurface(ennemi->image_enemy[i]);
}

int collisionbb( SDL_Rect posj , SDL_Rect posobj,SDL_Rect camera)
{
 int x ; 
if((posj.y+posj.h>=posobj.y)&&(posj.y<=posobj.y+posobj.h)&&(posj.x+camera.x+posj.w>=posobj.x)&&(posj.x+camera.x<=posobj.x+posobj.w)) 
{
	x=1 ; 
}
else x=0 ; 
return x ;
}
