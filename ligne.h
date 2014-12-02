#ifndef LIGNE_H
#define LIGNE_H

//#include <g2.h>
//#include <g2_PS.h>
//#include <g2_X11.h>

#include <iostream>
#include "point.h"
#include "canevas.h"
//-------------------------------------------------------------------------
// Type abstrait Ligne
// permet de definir une ligne a partir de deux point et de l'afficher sur le canevas
// definit aussi une serie d'operations sur la ligne
//---------------------------------------------------------------------------
class Ligne
{
    Point point1, point2;
    int couleur;

  public:
    // Constructeurs pour le ligne
    Ligne(Point debut,Point fin, int couleur);
    Ligne(Point debut,Point fin);
    Ligne(int couleur);
    Ligne();

    // fonciton qui affiche la logne sur le Canevas
    void afficher(Canevas &cv);

    // Fonction pour voir et modifier les attributs de la classe
    Point valPoint1() { return point1; };
    Point valPoint2() { return point2; };
    int valCouleur() { return couleur; };
    void changePoint1(Point nouvPoint);
    void changePoint2(Point nouvPoint);
    void changeCouleur(int couleur);

    // Fonctions pour re-initialiser la classe
    void init(Point debut,Point fin, int couleur);
    void init(Point debut,Point fin);
};

#endif
