#include <iostream>
#include <cstdlib>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <sstream>
#include <ctime>
#include "level.h"

#include "duck.h"

/*test*/

using namespace std;

const int ECRAN_WIDTH = 751;
const int ECRAN_HEIGHT = 761;
const int NB_CANARD_TO_WIN = 6;
const int NB_CANARD_PAR_NIVEAU = 10;

int alea(int max)
{
    return 1 + (int) (1.0*max * rand() / RAND_MAX);
}



int main(int argc, char* argv[])
{
     niveau n;
     int difficulte = 0;

     initNiveau(n,difficulte);

      SDL_Surface *canard1;

     return EXIT_SUCCESS;
}


/****************** Nom de la fonction **********************
* NOM_FONCTION                                              *
******************** Auteur , Dates *************************
* Nom/Date : Éventuellement la version                      *
********************* Description ***************************
* Vous décrivez ici ce que fait cette fonction              *
*********************** Entrées *****************************
* Vous décrivez ici les données en entrée de la fonction    *
*********************** Sorties *****************************
* Vous détaillez ici ce que renvoie la fonction             *
************************************************************/
