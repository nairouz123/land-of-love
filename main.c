#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"game.h"

int  main()
{

SDL_Surface *screen;
SDL_Rect positionecran;
SDL_Event event;



enemy E;


    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Game", NULL);
 initialiser_enemy(&E);
deplacement_aleatoire(E,screen);
freesurfaceennemi(&E);
    SDL_Quit();

}
