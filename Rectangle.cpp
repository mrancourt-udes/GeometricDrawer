/** **************************************************************
 \file rectangle.cpp
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'implementation de la classe rectangle
 *****************************************************************/

#include "Rectangle.h"
#include "ligne.h"

// Constructeur par defaut
Rectangle::Rectangle()
{
    point1.init(0, 0);
    point2.init(0, 0);
    point3.init(0, 0);
    point4.init(0, 0);
}

Rectangle::Rectangle(Point point1, Point point2)
{
    this->point1 = point1;
    this->point2 = point2;
}

Rectangle::Rectangle(Point point1, Point point2, int couleur)
{
    this->point1 = point1;
    this->point2 = point2;
    this->couleur = couleur;
}

void Rectangle::init()
{    
    point3.init(point2.valX(), point1.valY());
    point4.init(point1.valX(), point2.valY());
}

// Lectures des informations du rectangle
void Rectangle::lecture()
{
    cout << "Point 1 : ";
    point1.lecture();

    cout << "Point 2 : ";
    point2.lecture();
    
    // Initialisation des points 3 et 4
    init();
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

Point Rectangle::valPoint3()
{
    return point3;
}

Point Rectangle::valPoint4()
{
    return point4;
}

int Rectangle::valCouleur()
{
    return couleur;
}

Point Rectangle::valCentre()
{
    // Declaration des constantes
    const int NB_POINTS = 2;
    
    // Todo : Corriger les calculs
    int centreX;
    int centreY;
    
    centreX = ((point1.valX() + point2.valX()) / NB_POINTS);
    centreY = ((point1.valY() + point2.valY()) / NB_POINTS);
    
    Point pointCentral(centreX, centreY);
    
    return pointCentral;
}

void Rectangle::changerPoint1(Point point)
{
    point1 = point;
}

void Rectangle::changerPoint2(Point point)
{
    point2 = point;
}

void Rectangle::changerPoint3(Point point)
{
    point3 = point;
}

void Rectangle::changerPoint4(Point point)
{
    point4 = point;
}

void Rectangle::changerCouleur(int nouvelleCouleur)
{
    couleur = nouvelleCouleur;
}

void Rectangle::effectuerRotation(float angleRadian)
{
    point1.rotation(valCentre(), angleRadian);
    point2.rotation(valCentre(), angleRadian);
    point3.rotation(valCentre(), angleRadian);
    point4.rotation(valCentre(), angleRadian);
}

void Rectangle::deplacer(int dx, int dy)
{
    point1.deplacement(dx, dy);
    point2.deplacement(dx, dy);
}

void Rectangle::modifierTaille(Point pointCentral, float proportion)
{
    point1.deplacementProp(pointCentral, proportion);
    point2.deplacementProp(pointCentral, proportion);
    point3.deplacementProp(pointCentral, proportion);
    point4.deplacementProp(pointCentral, proportion);
}

void Rectangle::dessiner(Canevas canevas)
{
    // Premiere ligne
    Ligne ligne(point1, point3);
    ligne.afficher(canevas);
    
    // Deuxieme ligne
    ligne.init(point3, point2);
    
    // Troisieme ligne
    ligne.init(point3, point4);
    
    // Quatrieme ligne
    ligne.init(point4, point1);
}

string Rectangle::enString()
{
    string str =
    "(" + to_string(point1.valX()) + "," + to_string(point1.valY()) + ")-" +
    "(" + to_string(point3.valX()) + "," + to_string(point3.valY()) + ")\n" +
    "(" + to_string(point4.valX()) + "," + to_string(point4.valY()) + ")-"+
    "(" + to_string(point2.valX()) + "," + to_string(point2.valY()) + ")\n";
    
    return str;
}