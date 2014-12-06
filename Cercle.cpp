/** **************************************************************
 \file cercle.cpp
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief Fichier d'implementation de la classe cercle
 *****************************************************************/

#include <cmath>

#include "Cercle.h"
#include "ligne.h"

using namespace std;

// Constructeur par defaut
Cercle::Cercle()
{
    pointCentral.init(0, 0);
    rayon = 0;
}

// Constructeur parametre
Cercle::Cercle(Point pointCentral, int rayon)
{
    this->pointCentral = pointCentral;
    this->rayon = rayon;
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de lire le point central et le rayon du cercle.
 ----------------------------------------------------------------------- **/
void Cercle::lecture()
{
    // Lecture des informations du cercle
    cout << "Point central : ";
    pointCentral.lecture();

    cout << "Rayon : ";
    cin >> rayon;
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de faire le déplacement du cercle
 \param [in] dx : Deplacement en x
 \param [in] dy : Deplacement en y
 ----------------------------------------------------------------------- **/
void Cercle::deplacer(int dx, int dy)
{
    pointCentral.deplacement(dx, dy);
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de faire modifier la taille du cercle
 \param [in] PointCentralModification : Point central de modification de taille
 \param [in] proportion : proportion de la modification de la taille
 ----------------------------------------------------------------------- **/
void Cercle::modifierTaille(Point pointCentralModification, float proportion)
{
    pointCentral.deplacementProp(pointCentralModification, proportion);
    rayon *= proportion;
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de dessiner un cercle
 \param [in,out] canevas : canevas de dessin
 ----------------------------------------------------------------------- **/
void Cercle::dessiner(Canevas &canevas)
{
    // Declaration des constantes
    const int NB_ANGLES = 90;
    const int TOUR_COMPLET = 360;

    // Declaration des variables
    float alpha = 0.0f;
    float epsilon = float(NB_ANGLES) / float(TOUR_COMPLET);

    // On dessine le cercle en 90 segments
    for (int i = 0; i < NB_ANGLES; i++)
    {
        int p1X = pointCentral.valX() + (rayon * cos(alpha));
        int p1Y = pointCentral.valY() + (rayon * sin(alpha));
        int p2X = pointCentral.valX() + (rayon * cos(alpha + epsilon));
        int p2Y = pointCentral.valY() + (rayon * sin(alpha + epsilon));

        Point p1(p1X, p1Y);
        Point p2(p2X, p2Y);

        Ligne ligne(p1, p2);
        ligne.afficher(canevas);

        alpha += epsilon;
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module d'afficher les information du cercle
 \return str : chaine de caracteres contenant l'information
 ----------------------------------------------------------------------- **/
string Cercle::enString()
{
    string str =
    "Point central : (" + to_string(pointCentral.valX()) + "," + to_string(pointCentral.valY()) + ") \n" +
    "Rayon : " + to_string(rayon) + "\n";

    return str;
}
