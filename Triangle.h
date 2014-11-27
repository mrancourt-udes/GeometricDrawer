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
    Triangle(Point, Point, Point, int);
    
    // Getters
    Point valPoint1();
    Point valPoint2();
    Point valPoint3();
    int valCouleur();
    
    // Setters
    void changerPoints(Point, Point, Point);
    void changerCouleur(int);
    
    // Methode qui calcule la valeur centrale du triangle
    Point valCentre();
    
    // Methode pour effectuer une rotation sur un triangle
    void effectuerRotation();
    
    // Methode pour deplacer un cercle
    void deplacer();
    
    // Methode pour modifier la taille d'un triangle
    void modifierTaille();
    
    // Methode pour dessiner un triangle
    void dessiner();
    
    // Pour lecture
    void lecture();
    
    void setCoordonnees(Point, Point, Point);
    
    // Conversion de l'objet en string
    string toString();
    
};

#endif /* defined(__TRIANGLE_H__) */
