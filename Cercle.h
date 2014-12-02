/** **************************************************************
 \file cercle.h
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'en-tete de la classe cercle
 *****************************************************************/

#ifndef __CERCLE_H_
#define __CERCLE_H_

#include <stdio.h>
#include <string>
#include <cmath>

#include "Point.h"
#include "canevas.h"

using namespace std;

/** ----------------------------------------------------------------------
 \brief Definition de la classe cercle (entetes)
 ----------------------------------------------------------------------- **/
class Cercle
{
    // Attributs
    Point pointCentral;
    int rayon;
    int couleur;
    
public:
    // Constructeurs
    Cercle();
    Cercle(Point, int);
    Cercle(Point, int, int);
    
    // Getters
    Point valCentre();
    float valRayon();
    int   valCouleur();
    
    // Setters
    void changerCentre(Point);
    void changerRayon(int);
    void changerCouleur(int);

    // Methode pour deplacer un cercle
    void deplacer(int deltaX, int deltaY);
    
    // Methode pour modifier la taille d'un cercle
    void modifierTaille(Point, float);
    
    // Methode pour dessiner un cercle
    void dessiner(Canevas);
    
    // Pour lecture
    void lecture();
    
    // Conversion de l'objet en string
    string enString();
};

#endif /* defined(__CERCLE_H_) */
