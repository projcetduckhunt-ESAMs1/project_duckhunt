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

const int TAILLE=70;

/****************** Nom de la fonction **********************
* alea                                                      *
******************** Auteur , Dates *************************
* Nom/Date : Professeur de l'iut informatique de bdx        *
********************* Description ***************************
* Permet de generer un nombre aléatoire                     *
*********************** Entrées *****************************
* Nombre macimum                                            *
*********************** Sorties *****************************
* Renvoi le chiffre tir au sort                             *
************************************************************/
int alea(int max)
{

    return(1 + (int) (1.0*max * rand() / RAND_MAX));
}


/****************** Nom de la fonction **********************
* initCanard                                                *
******************** Auteur , Dates *************************
* Nom/Date : Enzo Sagnelonge                                *
********************* Description ***************************
* Permet d'initialiser le canard                            *
*********************** Entrées *****************************
* La structure du canard                                    *
*********************** Sorties *****************************
* Pas de sortie dans une void                               *
************************************************************/

void initCanard(canard &c)
{
    int tab[2];
    tab[0]=-2;
    tab[1]=2;

    cout << "Initialisation du canard passe en parametre !" << endl;
    c.couleur= rand()%3;
    c.vitesses=c.couleur/3;
    cout << c.couleur<<endl;
    c.vitesse;
    c.x=rand()%350;
    c.y=rand()%150;
    c.w=80;
    c.h=70;
    c.mvt_x=tab[(rand()%2)];
    c.mvt_y=tab[(rand()%2)];
    c.state= rand()%2;
    c.estvivant=true;
    c.del=false;

}


/****************** Nom de la fonction **********************
* moveDuck                                                  *
******************** Auteur , Dates *************************
* Nom/Date : Modifié Enzo Sagnelonge Réaliser par les       *
* professeur de l'iut informatique de bdx                   *
********************* Description ***************************
* Permet au canard de bouger / colisions / De faire disparai*
* tre le canard lorsqu'il est mort                          *
*********************** Entrées *****************************
* La structure du canard  et le nombre de balle             *
*********************** Sorties *****************************
* Pas de sortie dans une void                               *
************************************************************/
void moveDuck(canard &c, int nbball)
{
    SDL_Rect tmp;

    c.x+=c.mvt_x;

    tmp.x=c.x-TAILLE/2;
    tmp.y=c.y-TAILLE/2;
    tmp.h=TAILLE;
    tmp.w=TAILLE;

    // Correction Mouvement Horizontal
    if((c.x+TAILLE>SCREEN_WIDTH|| c.x<0) && c.estvivant==true)
    {
        c.x-=c.mvt_x;
        c.mvt_x*=-1;
    }

    if(nbball==0 && c.estvivant==true){
        c.mvt_y=-4;
        c.mvt_x=0;
    }


    c.y+=c.mvt_y;

    tmp.x=c.x-TAILLE/2;
    tmp.y=c.y-TAILLE/2;

    // Correction Mouvement Vertical
    if(((c.y+TAILLE>480) || (c.y<0)) && c.estvivant==true)
    {
        c.y-=c.mvt_y;
        c.mvt_y*=-1;
    }else if(((c.y+TAILLE>580 ) && c.estvivant==false) || (((c.y<5)) && nbball==0)){
        c.del=true;
        c.estvivant=false;
    }
}

/****************** Nom de la fonction **********************
* showDuck                                                  *
******************** Auteur , Dates *************************
* Nom/Date : Réaliser par les professeur de l'iut           *
* informatique de bdx                                       *
********************* Description ***************************
* Permet d'associer l'image à la structure*
*********************** Entrées *****************************
* La structure du canard et sa surface                      *
*********************** Sorties *****************************
* Pas de sortie dans une void                               *
************************************************************/

void showDuck(canard c, SDL_Surface *s )
{
    SDL_Rect r;
    r.x=c.x-TAILLE/2;
    r.y=c.y-TAILLE/2;
    r.w=TAILLE;
    r.h=TAILLE;

    SDL_FillRect(s,&r,SDL_MapRGB(s->format,255,164,255));
}

/****************** Nom de la fonction **********************
* applySurface                                              *
******************** Auteur , Dates *************************
* Nom/Date : Réaliser par les professeur de l'iut           *
* informatique de bdx                                       *
********************* Description ***************************
* Permet d'afficher  l'image                                *
*********************** Entrées *****************************
* la position de l'image / la surface sourc et de           *
* destination et le cadre de lecture                        *
*********************** Sorties *****************************
* Pas de sortie dans une void                               *
************************************************************/
void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
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







SDL_Surface * load_image( string filename )
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;
    //Load the image
    loadedImage = SDL_LoadBMP( filename.c_str() );
    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }
    //Return the optimized image
    return optimizedImage;
}


void duckSprites(canard &duck, SDL_Surface* sprite, SDL_Surface* screen, int move, int count)
{
    int x, y, w,h,square;
    SDL_Rect border;

    if(duck.estvivant==true){
        switch(duck.couleur)
        {
        case 0: y= 230; break;
        case 1: y= 300; break;
        case 2: y= 370; break;
        default: cout << "Error" << endl; break;
        }

        switch(move)
        {
        case 0: x= 0; w= 68; h=66; break;
        case 1: x= 204; w= 68; h=66;break;
        default: cout << "Error" << endl; break;
        }

        square=count*w;
        if(square==(3*w))
            square=square%3;
        border.x= x+square;
        border.y= y;
        border.w= w;
        border.h= h;
    }else if(duck.estvivant==false && duck.del==false){
        switch(duck.couleur)
        {
        case 0: y= 230; break;
        case 1: y= 300; break;
        case 2: y= 370; break;
        default: cout << "Error" << endl; break;
        }
        x= 492; w= 68; h=66;

        border.x= x+(count%2*w);
        border.y= y;
        border.w= w;
        border.h= h;
        duck.mvt_x=0;
        duck.mvt_y=4;
    }
    else{
        duck.mvt_x=0;
        duck.mvt_y=0;
        x= 700; w= 0; h=0;
        border.x= x;
        border.y= y;
        border.w= w;
    }
    applySurface(duck.x, duck.y, sprite, screen, &border);
}


void vitesse(int round,canard duck1,canard duck2){
    switch(duck1.couleur)
    {
    case 0: duck1.mvt_x*=0.5 ;duck1.mvt_y=0.5; break;
    case 1: duck1.mvt_x*=0.75 ;duck1.mvt_y=0.75; break;
    case 2: duck1.mvt_x*=1 ;duck1.mvt_y=1 ; break;
    default: cout << "Error" << endl; break;
    }
    switch(duck2.couleur)
    {
    case 0: duck2.mvt_x*=1 ;duck2.mvt_y=0.5; break;
    case 1: duck2.mvt_x*=1;duck2.mvt_y=1; break;
    case 2: duck2.mvt_x*=1 ;duck2.mvt_y=1 ; break;
    default: cout << "Error" << endl; break;
    }
}
