/** **************************************************************
 \file rectangle.cpp
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'implementation de la classe rectangle
 *****************************************************************/

#include "ligne.h"
#include "Rectangle.h"

using namespace std;

// Constructeur par defaut
Rectangle::Rectangle()
{
    point1.init(0, 0);
    point2.init(0, 0);
    init();
}

// Constructeur parametre
Rectangle::Rectangle(Point point1, Point point2)
{
    this->point1 = point1;
    this->point2 = point2;
    init();
}

/** ----------------------------------------------------------------------
 \brief Ce module permet d'initialiser les points manquants du rectangle
 ----------------------------------------------------------------------- **/
void Rectangle::init()
{
    // Initialisation des points 3 et 4
    point3.init(point2.valX(), point1.valY());
    point4.init(point1.valX(), point2.valY());
}
/** ----------------------------------------------------------------------
 \brief Ce module permet de lire les points du rectangle.
 ----------------------------------------------------------------------- **/
void Rectangle::lecture()
{
    // Lecture des points en diagonale
    cout << "Point 1 : ";
    point1.lecture();

    cout << "Point 2 : ";
    point2.lecture();

    // Initialisation des points 3 et 4
    init();
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de faire une rotation du rectangle
 \param [in] pointCentre : Centre de rotation
 \param [in] angleRadian : Angle de rotation
 ----------------------------------------------------------------------- **/
void Rectangle::effectuerRotation(Point pointCentre, float angleRadian)
{
    point1.rotation(pointCentre, angleRadian);
    point2.rotation(pointCentre, angleRadian);
    point3.rotation(pointCentre, angleRadian);
    point4.rotation(pointCentre, angleRadian);
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de faire le déplacement du rectangle
 \param [in] dx : Deplacement en x
 \param [in] dy : Deplacement en y
 ----------------------------------------------------------------------- **/
void Rectangle::deplacer(int dx, int dy)
{
    point1.deplacement(dx, dy);
    point2.deplacement(dx, dy);
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de faire modifier la taille du rectangle
 \param [in] PointCentral : Point central de modification de taille
 \param [in] proportion : proportion de la modification de la taille
 ----------------------------------------------------------------------- **/
void Rectangle::modifierTaille(Point pointCentral, float proportion)
{
    point1.deplacementProp(pointCentral, proportion);
    point2.deplacementProp(pointCentral, proportion);
    point3.deplacementProp(pointCentral, proportion);
    point4.deplacementProp(pointCentral, proportion);
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de dessiner un rectangle
 \param [in,out] canevas : canevas de dessin
 ----------------------------------------------------------------------- **/
void Rectangle::dessiner(Canevas &canevas)
{
    // Premiere ligne
    Ligne ligne(point1, point3);
    ligne.afficher(canevas);

    // Deuxieme ligne
    Ligne ligne2(point2, point3);
    ligne2.afficher(canevas);

    // Troisieme ligne
    Ligne ligne3(point2, point4);
    ligne3.afficher(canevas);

    // Quatrieme ligne
    Ligne ligne4(point4, point1);
    ligne4.afficher(canevas);
}

/** ----------------------------------------------------------------------
 \brief Ce module d'afficher les information du triangle
 \return str : chaine de caracteres contenant l'information
 ----------------------------------------------------------------------- **/
string Rectangle::enString()
{
    string str =
    "(" + to_string(point1.valX()) + "," + to_string(point1.valY()) + ")-" +
    "(" + to_string(point3.valX()) + "," + to_string(point3.valY()) + ")\n" +
    "(" + to_string(point4.valX()) + "," + to_string(point4.valY()) + ")-"+
    "(" + to_string(point2.valX()) + "," + to_string(point2.valY()) + ")\n";

    return str;
}
