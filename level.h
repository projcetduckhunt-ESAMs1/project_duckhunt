#ifndef _NIVEAU_H_
#define _NIVEAU_H_

#include <iostream>
#include "duck.h"

const int NB_CANARD_PAR_NIVEAU = 10;

struct niveau
{
    canard listeCanard[NB_CANARD_PAR_NIVEAU];
    int difficulte;
    //... et tout plein de choses
};

//Définition des prototypes de fonctions
void initNiveau(niveau &n, int difficulte);

#endif
