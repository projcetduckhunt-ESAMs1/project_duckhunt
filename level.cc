using namespace std;
#include "level.h"




/***********TRAVAIL ENZO***************************/
void initNiveau(niveau &n, int difficulte )
{
   //initialisation du premier canard de ce niveau (il y en a 10 à faire)
   initCanard(n.listeCanard[0]);
   // trololo

   // Ceci est une diff
   //initialise la difficulté du niveau
   n.difficulte = difficulte;
}






/************TRAVAIL ARNO*******************/

void pause()
{
    bool esc= false;
    SDL_Event event_pause;

    while(!esc){
        Uint8 *temp = SDL_GetKeyState(NULL);
        SDL_WaitEvent(&event_pause);
        if(temp[SDLK_RETURN] == 1)
            esc=true;
    }

}


void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}

