//#include <g2.h>
//#include <g2_PS.h>
//#include <g2_X11.h>

#include "ligne.h"
#include "canevas.h"

const Point POINT_DEBUT(0,0);
const Point POINT_FIN(1,1);
const int COULEUR_PAR_DEFAUT = 0;
//-------------------------------------------------------------------------
// Type abstrait Ligne
// permet de definir une ligne a partir de deux point et de l'afficher sur le canevas
// definit aussi une serie d'operations sur la ligne
//
// **** Implantation des methodes
//---------------------------------------------------------------------------
// Constructeurs
Ligne::Ligne(Point debut, Point fin, int coul)
{

    point1=debut;
    point2=fin;
    couleur=coul;

}
Ligne::Ligne(Point debut, Point fin)
{
    point1=debut;
    point2=fin;
    couleur=COULEUR_PAR_DEFAUT;
}
Ligne::Ligne(int coul)
{
    point1=POINT_DEBUT;
    point2=POINT_FIN;
    couleur=coul;
}
Ligne::Ligne()
{
    point1=POINT_DEBUT;
    point2=POINT_FIN;
    couleur=COULEUR_PAR_DEFAUT;
}
//
// Affichage de la ligne sur le Canevas
//
void Ligne::afficher(Canevas &cv)
{
    // configure la couleur du crayon
    // g2_pen(cv.valIdentificateur(),couleur);
    // on dessine la ligne
    // g2_line(cv.valIdentificateur(), point1.valX(), point1.valY(), point2.valX(), point2.valY());
}
//
// Methodes pour voir et modifier les attributs
//
void Ligne::changePoint1(Point nouvPoint)
{
    point1=nouvPoint;
}
void Ligne::changePoint2(Point nouvPoint)
{
    point2=nouvPoint;
}
void Ligne::changeCouleur(int nouvCouleur)
{
    couleur=nouvCouleur;
}
void Ligne::init(Point debut, Point fin, int coul)
{
   point1=debut;
   point2=fin;
   couleur=coul;
}
//
// Methodes pour re-initialiser la ligne
//
void Ligne::init(Point debut, Point fin)
{
   point1=debut;
   point2=fin;
   couleur=COULEUR_PAR_DEFAUT;
}
