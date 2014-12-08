#ifndef CANEVAS_H
#define CANEVAS_H

#include <g2.h>
#include <g2_PS.h>
#include <g2_X11.h>

#include <iostream>
using namespace std;
//
// Classe qui definit l'ecran d'affichage (canevas)
//
class Canevas
{
    int identificateur;
    int tailleX, tailleY;     // taille de l'ecran
    int couleurDeFond;

  public:

    // constructeurs
    Canevas(int tx, int ty, int fond);
    Canevas(int tx, int ty);
    Canevas(int fond);
    Canevas();
    // destructeur
    ~Canevas();
    // fonction qui efface tout sur le canevas
    void effacer();
    // fonction qui retourne les valeurs de elements
    int valX() { return tailleX; };
    int valY() { return tailleY; };
    int valIdentificateur() { return identificateur;};
    int valCouleur() { return couleurDeFond;};
};

#endif
