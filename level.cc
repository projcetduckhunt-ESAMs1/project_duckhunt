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
