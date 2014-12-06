#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iostream>

using namespace std;
//
// Definition de la classe Point (entetes)
//
class Point
{
    int coordonneeX,coordonneeY;
    
public:
    
    // constructeurs
    Point(int x, int y);
    Point();
    
    // pour re-initialisation
    void init(int x, int y);
    
    // pour lecture
    void lecture();
    
    // pour obtenir les valeurs du Point
    int valX();
    int valY();
    
    // fonction pour la mise au Point
    void afficher(void);
    
    //Fonction pour faire tourner un Point autour d'un centre
    void rotation(Point centre, float angleRadian);
    
    // fonction pour deplacer un Point en absolu.  Les parametres sont des
    // deplacement par rapport a la position courante.
    void deplacement(int deltaX, int deltaY);
    
    // fonction pour deplacer un Point proportionnellement a un centre.
    // Les parametres sont le Point de reference un la proportion du deplacement
    void deplacementProp(Point ancre, float proportion);
    
};
#endif
