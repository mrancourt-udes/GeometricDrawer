/** **************************************************************
 \file rectangle
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'en-tete de la classe rectangle
 *****************************************************************/

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <stdio.h>
#include <string>

#include "Point.h"

class Rectangle
{
    // Attributs
    Point point1;
    Point point2;
    int couleur;
    
public:
    // Constructeurs
    Rectangle();
    Rectangle(Point, Point);
    
    // Getters
    Point valPoint1();
    Point valPoint2();
    int valCouleur();
    
    // Setters
    void changerPoints(Point, Point);
    void changerCouleur(int);
    
    // Methode qui calcule la valeur centrale du rectangle
    Point valCentre();
    
    // Methode pour effectuer une rotation sur un rectangle
    void effectuerRotation();
    
    // Methode pour deplacer un rectangle
    void deplacer();
    
    // Methode pour modifier la taille d'un rectangle
    void modifierTaille();
    
    // Methode pour dessiner un cercle
    void dessiner();
    
    // Pour lecture
    void lecture();
    
    // Conversion de l'objet en string
    string toString();
};

#endif /* defined(__RECTANGLE_H__) */
