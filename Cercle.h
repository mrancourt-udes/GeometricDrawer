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

#include "Point.h"

using namespace std;

class Cercle
{
    Point pointCentral;
    float rayon;
    int couleur;
    
public:
    // Constructeurs
    Cercle();
    Cercle(Point, float);
    
    // Get/Set
    Point valCentre();
    float valRayon();
    int   valCouleur();
    
    void changerCentre(Point);
    void changerRayon(float);
    void changerCouleur(int);
    
    void dessiner();
    
    // Pour lecture
    void lecture();
    
    // Conversion de l'objet en string
    string toString();
};

#endif /* defined(__CERCLE_H_) */
