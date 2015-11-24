#ifndef _CANARD_H_
#define _CANARD_H_

#include <iostream>
#include <stdlib.h>
//... tous les includes nécessaires

//Constantes

// Définitions des structures
struct canard
{
  int couleur;    //0 noir 1 rouge et 2 bleu
  int vitesse;    //vitesse du canard (pour gérer son déplacement)
  int x;       //position x sur le champ de tir
  int y;       //position y sur le champ de tir
  int w;          //Largeur
  int h;          //Hauteur
  int mvt_x;      // mouvement sur l'axe des abscisses
  int mvt_y;      // mouvement sur l'axe des ordonnées

};



//Définitions des prototypes de fonctions
void initCanard(canard &c);


#endif
