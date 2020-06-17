
#include "minimapfunc.h"

void miniMap (SDL_Surface *screen , SDL_Rect pos_perso, char mini_backgroundx[],char mini_persox[] ,SDL_Rect camera ){

SDL_Rect pos_mini_perso;
SDL_Surface *mini_background=NULL;
SDL_Surface *mini_perso=NULL;
	mini_background=IMG_Load(mini_backgroundx);
mini_perso=IMG_Load(mini_persox);


SDL_SetColorKey(mini_perso,SDL_SRCCOLORKEY,SDL_MapRGB(mini_perso->format,255,255,255));
//pos_perso.x=camera.x;
	pos_mini_perso.x=(pos_perso.x)*0.056521;
	pos_mini_perso.y=(pos_perso.y)*0.07;

	SDL_BlitSurface(mini_background,NULL,screen,0);
	SDL_BlitSurface(mini_perso,NULL,screen,&pos_mini_perso);

//SDL_FreeSurface(mini_background);
//SDL_FreeSurface(mini_perso);
}
