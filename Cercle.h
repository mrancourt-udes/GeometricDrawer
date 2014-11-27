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

/** ----------------------------------------------------------------------
 \brief Definition de la classe cercle (entetes)
 ----------------------------------------------------------------------- **/
class Cercle
{
    // Attributs
    Point pointCentral;
    float rayon;
    int couleur;
    
public:
    // Constructeurs
    Cercle();
    Cercle(Point, float);
    
    // Getters
    Point valCentre();
    float valRayon();
    int   valCouleur();
    
    // Setters
    void changerCentre(Point);
    void changerRayon(float);
    void changerCouleur(int);
    
    // Methode pour effectuer une rotation sur un cercle
    void effectuerRotation();
    
    // Methode pour deplacer un cercle
    void deplacer();
    
    // Methode pour modifier la taille d'un cercle
    void modifierTaille();
    
    // Methode pour dessiner un cercle
    void dessiner();
    
    // Pour lecture
    void lecture();
    
    // Conversion de l'objet en string
    string toString();
};

#endif /* defined(__CERCLE_H_) */
