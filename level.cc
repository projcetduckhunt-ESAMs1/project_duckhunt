using namespace std;
#include "level.h"

// Fonctions
void initNiveau(niveau &n, int difficulte )
{
   //initialisation du premier canard de ce niveau (il y en a 10 à faire)
   initCanard(n.listeCanard[0]);

   //initialise la difficulté du niveau
   n.difficulte = difficulte;
}


void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

void tirer(int &nbballe,int &score,canard a,canard b){
    int x = event.button.x;
    int y = event.button.y;

    nbballe--;


        if((x>a.x)&&(x<a.x+a.w)&&(y>a.y)&&(y<a.y+a.h))
                   {
                        score+=1;//a modif
                        SDL_FreeSurface(a);
                   }
        if((x>b.x)&&(x<b.x+b.w)&&(y>b.y)&&(y<b.y+b.h))
                   {
                             score+=1;//a modif
                             SDL_FreeSurface(b);
                   }




}
