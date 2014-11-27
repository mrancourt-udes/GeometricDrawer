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
    Point point1;
    Point point2;
    int couleur;
    
public:
    // Constructeurs
    Rectangle();
    Rectangle(Point, Point);
    
    // Get/Set
    Point valPoint1();
    Point valPoint2();
    int valCouleur();
    Point valCentre();
    
    void changerPoints(Point, Point);
    void changerCouleur(int);
    
    void effectuerRotation();
    void deplacer();
    void modifierTaille();
    
    void dessiner();
    
    // Pour lecture
    void lecture();
    
    // Conversion de l'objet en string
    string toString();
};

#endif /* defined(__RECTANGLE_H__) */
