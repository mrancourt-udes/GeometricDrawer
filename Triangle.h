/** **************************************************************
 \file triangle.h
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'en-tete de la classe triangle
 *****************************************************************/

#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <string>

#include "canevas.h"
#include "Point.h"

using namespace std;

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
    void changerPoint1(Point);
    void changerPoint2(Point);
    void changerPoint3(Point);
    void changerCouleur(int);
    
    // Methode qui calcule la valeur centrale du triangle
    Point valCentre();
    
    // Methode pour effectuer une rotation sur un triangle
    void effectuerRotation(Point, float);
    
    // Methode pour deplacer un triangle
    void deplacer(int deltaX, int deltaY);
    
    // Methode pour modifier la taille d'un triangle
    void modifierTaille(Point, int);
    
    // Methode pour dessiner un triangle
    void dessiner(Canevas &);
    
    // Pour lecture
    void lecture();
    
    // Conversion de l'objet en string
    string enString();
    
};

#endif /* __TRIANGLE_H__ */
