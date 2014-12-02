/** **************************************************************
 \file cercle.cpp
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'implementation de la classe cercle
 *****************************************************************/

#include <cmath>
#include "Cercle.h"
#include "ligne.h"

// Constructeur par defaut
Cercle::Cercle()
{
    pointCentral.init(0, 0);
    rayon = 0;
}

Cercle::Cercle(Point pointCentral, int rayon)
{
    this->pointCentral = pointCentral;
    this->rayon = rayon;
}

Cercle::Cercle(Point pointCentral, int rayon, int couleur)
{
    this->pointCentral = pointCentral;
    this->rayon = rayon;
    this->couleur = couleur;
}

Point Cercle::valCentre()
{
    return pointCentral;
}

float Cercle::valRayon()
{
    return rayon;
}

int Cercle::valCouleur()
{
    return couleur;
}

void Cercle::changerCentre(Point point)
{
    pointCentral = point;
}

void Cercle::changerRayon(int rayon) {
    rayon = rayon;
}

void Cercle::changerCouleur(int couleur)
{
    couleur = couleur;
}

// Lectures des informations du cercle
void Cercle::lecture()
{
    cout << "Point central : ";
    pointCentral.lecture();
    
    cout << "Rayon : ";
    cin >> rayon;
}

void Cercle::deplacer(int dx, int dy)
{
    pointCentral.deplacement(dx, dy);
}

void Cercle::modifierTaille(Point pointCentralModification, float proportion)
{
    pointCentral.deplacementProp(pointCentralModification, proportion);
    rayon *= proportion;
}

void Cercle::dessiner(Canevas canevas)
{
    
    const int NB_ANGLES = 40;
    const int TOUR_COMPLET = 360;
    
    int alpha = 0;
    int epsilon = NB_ANGLES / TOUR_COMPLET;
    
    for (int i = 0; i < NB_ANGLES; i++)
    {
        int p1X = pointCentral.valX() + (rayon * cos(alpha));
        int p1Y = pointCentral.valY() + (rayon * cos(alpha));
        int p2X = pointCentral.valX() + (rayon * cos(alpha + epsilon));
        int p2Y = pointCentral.valY() + (rayon * cos(alpha + epsilon));
        
        Point p1(p1X, p1Y);
        Point p2(p2X, p2Y);
        
        Ligne ligne(p1, p2);
        ligne.afficher(canevas);
        
        alpha += epsilon;
    }
}

string Cercle::enString()
{
    string str =
    "Point central : (" + to_string(pointCentral.valX()) + "," + to_string(pointCentral.valY()) + ") \n" +
    "Rayon : " + to_string(rayon) + "\n";
    
    return str;
}