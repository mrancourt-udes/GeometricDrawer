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
#include "canevas.h"

class Rectangle
{
    // Attributs
    Point point1;
    Point point2;
    Point point3;
    Point point4;
    int couleur;
    
    // Methode d'initialisation
    void init();
    
public:
    // Constructeurs
    Rectangle();
    Rectangle(Point, Point);
    Rectangle(Point, Point, int);
    
    // Getters
    Point valPoint1();
    Point valPoint2();
    Point valPoint3();
    Point valPoint4();
    int valCouleur();
    
    // Setters
    void changerPoint1(Point);
    void changerPoint2(Point);
    void changerPoint3(Point);
    void changerPoint4(Point);
    void changerCouleur(int);
    
    // Methode qui calcule la valeur centrale du rectangle
    Point valCentre();
    
    // Methode pour effectuer une rotation sur un rectangle
    void effectuerRotation(float);
    
    // Methode pour deplacer un rectangle
    void deplacer(int deltaX, int deltaY);
    
    // Methode pour modifier la taille d'un rectangle
    void modifierTaille(Point, float);
    
    // Methode pour dessiner un cercle
    void dessiner(Canevas);
    
    // Pour lecture
    void lecture();
    
    // Conversion de l'objet en string
    string enString();
};

#endif /* defined(__RECTANGLE_H__) */
