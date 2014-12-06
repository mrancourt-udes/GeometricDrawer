#include <cmath>
#include <iostream>

#include "point.h"

using namespace std;
//-------------------------------------------------------------------------
// Type abstrait Point
// permet de definir un point a partir de deux coordonnees
// definit aussi une serie d'operations sur le point
//
// **** Implantation des methodes
//---------------------------------------------------------------------------
// Constructeurs
Point::Point(int x, int y)
{
    coordonneeX = x;
    coordonneeY = y;
}
Point::Point()
{
    coordonneeX = 0;
    coordonneeY = 0;
}
void Point::init(int x, int y)
{
    coordonneeX = x;
    coordonneeY = y;
}
// Methode pour retourner les valeurs des coordonnees
int Point::valX()
{
    return coordonneeX;
}
int Point::valY()
{
    return coordonneeY;
}
// lecture des coordonnes du point
void Point::lecture()
{
    cin >> coordonneeX >> coordonneeY;
}
// Affichage à l'écran des coordonnees du point
void Point::afficher(void)
{
    cout << "(" << coordonneeX << "," << coordonneeY << ")";
}
// Rotation d'un point autour d'un autre point
void Point::rotation(Point centre, float angle)
{
    int xTemp, yTemp;
    
    coordonneeX = coordonneeX - centre.coordonneeX;
    coordonneeY = coordonneeY - centre.coordonneeY;
    
    xTemp =  int(coordonneeX * cos(angle) - coordonneeY * sin(angle));
    yTemp = int(coordonneeY * cos(angle) + coordonneeX * sin(angle));
    
    coordonneeX = xTemp + centre.coordonneeX;
    coordonneeY = yTemp + centre.coordonneeY;
    
}
// Deplacement absolu d'un point
void Point::deplacement(int dx, int dy)
{
    coordonneeX = coordonneeX + dx;
    coordonneeY = coordonneeY + dy;
}
// deplacement proportionnel d'un point
void Point::deplacementProp(Point ancre,float delta)
{
    coordonneeX = int((coordonneeX - ancre.coordonneeX) * delta) + ancre.coordonneeX;
    coordonneeY = int((coordonneeY - ancre.coordonneeY) * delta) + ancre.coordonneeY;
}
