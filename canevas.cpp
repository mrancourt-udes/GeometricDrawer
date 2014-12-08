#include <iostream>
#include <unistd.h>

#include "canevas.h"

const int TAILLE_PAR_DEFAUT = 600;
const int COULEUR_PAR_DEFAUT = 1;
//
// Constructeur
//
Canevas::Canevas(int tX, int tY, int fond)
{
    tailleX=tX;
    tailleY=tY;
    couleurDeFond=fond;
    //   identificateur = g2_open_PS("sortie", g2_Letter, g2_PS_port);
    identificateur = g2_open_X11(tailleX,tailleY);
    g2_set_background(identificateur, couleurDeFond);
}
//
// Constructeur
//
Canevas::Canevas(int tX, int tY)
{
    tailleX=tX;
    tailleY=tY;
    couleurDeFond=COULEUR_PAR_DEFAUT;
    //  identificateur = g2_open_PS("sortie", g2_Letter, g2_PS_port);
    identificateur = g2_open_X11(tailleX,tailleY);
    g2_set_background(identificateur, couleurDeFond);
}
//
// Constructeur
//
Canevas::Canevas(int fond)
{
    tailleX=TAILLE_PAR_DEFAUT;
    tailleY=TAILLE_PAR_DEFAUT;
    couleurDeFond=fond;
    //   identificateur = g2_open_PS("sortie", g2_Letter, g2_PS_port);
    identificateur = g2_open_X11(tailleX,tailleY);
    g2_set_background(identificateur, couleurDeFond);
}

//
// Constructeur
//
Canevas::Canevas()
{
    tailleX=TAILLE_PAR_DEFAUT;
    tailleY=TAILLE_PAR_DEFAUT;
    couleurDeFond=COULEUR_PAR_DEFAUT;
    //   identificateur = g2_open_PS("sortie", g2_Letter, g2_PS_port);
    identificateur = g2_open_X11(tailleX,tailleY);
    g2_set_background(identificateur, couleurDeFond);
}
//
// Destructeur
//
Canevas::~Canevas()
{
   cout << "fin......................:" << endl;
   sleep(2);
   g2_close(identificateur);
}
//
// Fonction qui efface tout se qui se trouve sur le canevas
//
void Canevas::effacer()
{
    sleep(2);
    g2_clear(identificateur);
}


