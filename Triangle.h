/** **************************************************************
 \file triangle.h
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'en-tete de la classe triangle
 *****************************************************************/

#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <stdio.h>
#include <string>

#include "Point.h"


class Triangle
{
    // Membres prives
    Point point1;
    Point point2;
    Point point3;
    int couleur;
    
    // Methodes publiques
    public:
    
    // Constructeurs
    Triangle();
    Triangle(Point, Point, Point);
    
    // Get/Set
    Point valPoint1();
    Point valPoint2();
    Point valPoint3();
    int valCouleur();
    Point valCentre();
    
    void changerPoints(Point, Point, Point);
    void changerCouleur(int);
    
    void effectuerRotation();
    void deplacer();
    void modifierTaille();
    
    void dessiner();
    
    // Pour lecture
    void lecture();
    
    void setCoordonnees(Point, Point, Point);
    
    // Conversion de l'objet en string
    string toString();
    
};

#endif /* defined(__TRIANGLE_H__) */
