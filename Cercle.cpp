/** **************************************************************
 \file cercle.cpp
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'implementation de la classe cercle
 *****************************************************************/

#include "Cercle.h"

// Constructeur par defaut
Cercle::Cercle() {
    
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

void Cercle::changerRayon(float rayon) {
    rayon = rayon;
}

void Cercle::changerCouleur(int couleur)
{
    couleur = couleur;
}

// Lectures des informations du cercle
void Cercle::lecture()
{
    Point pointCentral;
    
    cout << "Point central : ";
    pointCentral.lecture();
    
    cout << "Rayon : ";
    cin >> rayon;
}

void Cercle::effectuerRotation()
{
    
}

void Cercle::deplacer()
{
    
}

void Cercle::modifierTaille()
{
    
}

void Cercle::dessiner()
{
    
}

string Cercle::toString()
{
    string str =
    "Point central : (" + to_string(pointCentral.valX()) + "," + to_string(pointCentral.valY()) + ") \n" +
    "Rayon : " + to_string(rayon) + "\n";
    
    return str;
}