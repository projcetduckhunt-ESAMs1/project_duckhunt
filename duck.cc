#include "duck.h"
#include "level.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <sstream>
using namespace std;

const int TAILLE=6;

int alea(int max)
{
    return 1 + (int) (1.0*max * rand() / RAND_MAX);
}

void initCanard(canard &c)
{
    int tab[2];
    tab[0]=-2;
    tab[1]=2;

    cout << "Initialisation du canard passe en parametre !" << endl;
    c.couleur = rand()%3;
    c.vitesse;
    c.x=350;
    c.y=150;
    c.w=80;
    c.h=70;
    c.mvt_x=tab[alea(2)-1];
    c.mvt_y=tab[alea(2)-1];
}
// (initialiser, déplacer, tuer, sauver, ...).

void moveDuck(canard &c)
{
    SDL_Rect tmp;

    c.x+=c.mvt_x;

    tmp.x=c.x-TAILLE/2;
    tmp.y=c.y-TAILLE/2;
    tmp.h=TAILLE;
    tmp.w=TAILLE;

    // Correction Mouvement Horizontal
    if(c.x+TAILLE>ECRAN_WIDTH|| c.x-TAILLE<0)
    {
        c.x-=c.mvt_x;
        c.mvt_x*=-1;
    }
    c.y+=c.mvt_y;

    tmp.x=c.x-TAILLE/2;
    tmp.y=c.y-TAILLE/2;

    // Correction Mouvement Vertical
    if((c.y+TAILLE>ECRAN_HEIGHT) || (c.y-TAILLE<0))
    {
        c.y-=c.mvt_y;
        c.mvt_y*=-1;
    }
}

void showDuck(canard c, SDL_Surface *s)
{
    SDL_Rect r;
    r.x=c.x-TAILLE/2;
    r.y=c.y-TAILLE/2;
    r.w=TAILLE;
    r.h=TAILLE;

    SDL_FillRect(s,&r,SDL_MapRGB(s->format,255,164,255));
}

void
applySurface(int x, int y, SDL_Surface* source,
             SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}

SDL_Surface *
loadImageWithColorKey(string filename, int r, int g, int b)
{
    SDL_Surface* loadedImage = NULL;

    SDL_Surface* optimizedImage = NULL;

    loadedImage = IMG_Load( filename.c_str() );

    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );

        SDL_FreeSurface( loadedImage );

        if( optimizedImage != NULL )
        {
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, r, g, b );

            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }
    return optimizedImage;
}
