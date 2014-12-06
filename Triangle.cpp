/** **************************************************************
 \file triangle.cpp
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'implementation de la classe triangle
 *****************************************************************/

#include "ligne.h"
#include "Triangle.h"

using namespace std;

// Constructeur par defaut
Triangle::Triangle()
{
    point1.init(0, 0);
    point2.init(0, 0);
    point3.init(0, 0);
}

// Constructeur parametre
Triangle::Triangle(Point point1, Point point2, Point point3)
{
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de lire les points du triangle.
 ----------------------------------------------------------------------- **/
void Triangle::lecture()
{
    // Lecture des points du triangle
    cout << "Point 1 : ";
    point1.lecture();

    cout << "Point 2 : ";
    point2.lecture();

    cout << "Point 3 : ";
    point3.lecture();
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de faire une rotation du triangle
 \param [in] pointCentre : Centre de rotation
 \param [in] angleRadian : Angle de rotation
 ----------------------------------------------------------------------- **/
void Triangle::effectuerRotation(Point pointCentre, float angleRadian)
{
    point1.rotation(pointCentre, angleRadian);
    point2.rotation(pointCentre, angleRadian);
    point3.rotation(pointCentre, angleRadian);
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de faire le déplacement du triangle
 \param [in] dx : Deplacement en x
 \param [in] dy : Deplacement en y
 ----------------------------------------------------------------------- **/
void Triangle::deplacer(int dx, int dy)
{
    point1.deplacement(dx, dy);
    point2.deplacement(dx, dy);
    point3.deplacement(dx, dy);
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de faire modifier la taille du triangle
 \param [in] PointCentral : Point central de modification de taille
 \param [in] proportion : proportion de la modification de la taille
 ----------------------------------------------------------------------- **/
void Triangle::modifierTaille(Point pointCentral, int proportion)
{
    point1.deplacementProp(pointCentral, proportion);
    point2.deplacementProp(pointCentral, proportion);
    point3.deplacementProp(pointCentral, proportion);
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de dessiner un triangle
 \param [in,out] canevas : canevas de dessin
 ----------------------------------------------------------------------- **/
void Triangle::dessiner(Canevas &canevas) const
{
    // Premiere ligne
    Ligne ligne(point1, point2);
    ligne.afficher(canevas);

    // Deuxieme ligne
    Ligne ligne2(point2, point3);
    ligne2.afficher(canevas);

    // Troisieme ligne
    Ligne ligne3(point3, point1);
    ligne3.afficher(canevas);
}

/** ----------------------------------------------------------------------
 \brief Ce module d'afficher les information du triangle
 \return str : chaine de caracteres contenant l'information
 ----------------------------------------------------------------------- **/
string Triangle::enString()
{
    string str =
    "Point 1 : (" + to_string(point1.valX()) + "," + to_string(point1.valY()) + ") \n" +
    "Point 2 : (" + to_string(point2.valX()) + "," + to_string(point2.valY()) + ") \n" +
    "Point 3 : (" + to_string(point3.valX()) + "," + to_string(point3.valY()) + ") \n";

    return str;
}
