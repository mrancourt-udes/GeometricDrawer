/** **************************************************************
 \file rectangle.h
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'en-tete de la classe rectangle
 *****************************************************************/

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <string>

#include "point.h"
#include "canevas.h"

/** ----------------------------------------------------------------------
 \brief Definition de la classe Rectangle (entetes)
 ----------------------------------------------------------------------- **/
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

    // Methode qui calcule la valeur centrale du rectangle
    Point valCentre();

    // Methode pour effectuer une rotation sur un rectangle
    void effectuerRotation(Point, float);

    // Methode pour deplacer un rectangle
    void deplacer(int deltaX, int deltaY);

    // Methode pour modifier la taille d'un rectangle
    void modifierTaille(Point, float);

    // Methode pour dessiner un cercle
    void dessiner(Canevas &);

    // Pour lecture
    void lecture();

    // Conversion de l'objet en string
    string enString();
};

#endif /* __RECTANGLE_H__ */
