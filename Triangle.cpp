/** **************************************************************
 \file triangle.cpp
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'implementation de la classe triangle
 *****************************************************************/

#include "Triangle.h"

// Constructeur par defaut
Triangle::Triangle()
{
    point1 = Point(0, 0);
    point2 = Point(0, 0);
    point3 = Point(0, 0);
}

Triangle::Triangle(Point point1, Point point2, Point point3)
{
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
}

Triangle::Triangle(Point point1, Point point2, Point point3, int couleur)
{
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
    this->couleur = couleur;
}

// Lectures des informations du rectangle
void Triangle::lecture()
{
    Point point1;
    Point point2;
    Point point3;
    
    cout << "Point 1 : ";
    point1.lecture();
    
    cout << "Point 2 : ";
    point2.lecture();
    
    cout << "Point 3 : ";
    point2.lecture();
}

// Get/Se
Point Triangle::valPoint1()
{
    return point1;
}

Point Triangle::valPoint2()
{
    return point2;
}

Point Triangle::valPoint3()
{
    return point3;
}

int Triangle::valCouleur()
{
    return couleur;
}

Point Triangle::valCentre()
{
    
    // Declaration des constantes
    const int NB_POINTS = 3;
    
    // Todo : Corriger les calculs
    int centreX;
    int centreY;
    
    centreX = ((point1.valX() + point2.valX() + point3.valX()) / NB_POINTS);
    centreY = ((point1.valY() + point2.valY() + point3.valY()) / NB_POINTS);
    
    Point pointCentral(centreX, centreY);
    
    return pointCentral;
}

void Triangle::changerPoint1(Point point)
{
    point1 = point;
}

void Triangle::changerPoint2(Point point)
{
    point2 = point;
}

void Triangle::changerPoint3(Point point)
{
    point3 = point;
}

void Triangle::changerCouleur(int nouvelleCouleur)
{
    couleur = nouvelleCouleur;
}

void Triangle::effectuerRotation()
{
    
}

void Triangle::deplacer()
{
    
}

void Triangle::modifierTaille()
{
    
}

void Triangle::dessiner()
{
    
}

string Triangle::enString()
{
    string str =
    "Point 1 : (" + to_string(point1.valX()) + "," + to_string(point1.valY()) + ") \n" +
    "Point 2 : (" + to_string(point1.valX()) + "," + to_string(point2.valY()) + ") \n" +
    "Point 3 : (" + to_string(point2.valX()) + "," + to_string(point3.valY()) + ") \n";
    
    return str;
}