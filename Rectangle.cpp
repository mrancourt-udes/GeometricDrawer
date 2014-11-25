/** **************************************************************
 \file rectangle.cpp
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'implementation de la classe rectangle
 *****************************************************************/

#include "Rectangle.h"

Rectangle::Rectangle()
{
    
}

// Lectures des informations du rectangle
void Rectangle::lecture()
{
    Point point1;
    Point point2;
    
    cout << "Point 1 : ";
    point1.lecture();

    cout << "Point 2 : ";
    point2.lecture();
}

// Get/Set
Point Rectangle::valPoint1()
{
    return point1;
}

Point Rectangle::valPoint2()
{
    return point2;
}

int Rectangle::valCouleur()
{
    return couleur;
}

void Rectangle::changerPoints(Point p1, Point p2)
{
    point1 = p1;
    point2 = p2;
}

void Rectangle::changerCouleur(int nouvelleCouleur)
{
    couleur = nouvelleCouleur;
}

string Rectangle::toString()
{
    string str =
    "Point 1 : (" + to_string(point1.valX()) + "," + to_string(point1.valY()) + ") \n" +
    "Point 2 : (" + to_string(point2.valX()) + "," + to_string(point2.valY()) + ") \n";
    
    return str;
}