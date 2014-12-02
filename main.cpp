/** **************************************************************
 \file tp6.cpp
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief TODO : resume
 *****************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "canevas.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

// Declaration des fonctions prototypes globales
void ajouter(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
void listerFigures(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
void listerFigures(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &, int);
int obtenirIndice(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &, int, bool);
void retirer(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
void effectuerRotation(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
void deplacer(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
void modifierTaille(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
void dessinerFigures (Canevas canevas, vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);

// Declaration des constantes globales
const char AJOUTER = 'a';
const char LISTER = 'l';
const char EFFACER = 'e';
const char EFFECTUER_ROTATION = 'r';
const char DEPLACER = 'd';
const char MODIFIER_TAILLE = 't';
const char QUITTER = 'q';
const int CERCLE = 1;
const int RECTANGLE = 2;
const int TRIANGLE = 3;
const string TRAIN = ">> ";

/** ----------------------------------------------------------------------
 \brief Point d'entree du logiciel de dessin.
 ----------------------------------------------------------------------- **/
int main()
{
    char commande;
    Canevas canevas;
    vector<Cercle> cercles;
    vector<Rectangle> rectangles;
    vector<Triangle> triangles;
    
    // On demande la commande a l'utilisateur
    cout << "Veuillez entrer une commande : " ;
    cin >> commande;
    cout << TRAIN + commande << endl;
    
    while (commande != QUITTER)
    {
        switch (commande) {
            case AJOUTER:
                // Ajout de la figure
                ajouter(cercles, rectangles, triangles);
                // On effate tout le canevas
                canevas.effacer();
                // On redessine chacune des fogures
                dessinerFigures(canevas, cercles, rectangles, triangles);
                break;
            case LISTER:
                // Lister les figures
                listerFigures(cercles, rectangles, triangles, 0);
                break;
                
            case EFFACER:
                // Supprimer une figure
                retirer(cercles, rectangles, triangles);
                // On effate tout le canevas
                canevas.effacer();
                // On redessine chacune des fogures
                dessinerFigures(canevas, cercles, rectangles, triangles);
                break;
                
            case EFFECTUER_ROTATION:
                // Effectuer une rotation sur une figure
                effectuerRotation(cercles, rectangles, triangles);
                // On effate tout le canevas
                canevas.effacer();
                // On redessine chacune des fogures
                dessinerFigures(canevas, cercles, rectangles, triangles);
                break;
                
            case DEPLACER:
                // Deplacer une figure
                deplacer(cercles, rectangles, triangles);
                // On effate tout le canevas
                canevas.effacer();
                // On redessine chacune des fogures
                dessinerFigures(canevas, cercles, rectangles, triangles);
                break;
                
            case MODIFIER_TAILLE:
                // Modifier la taille d'une figure
                modifierTaille(cercles, rectangles, triangles);
                // On effate tout le canevas
                canevas.effacer();
                // On redessine chacune des fogures
                dessinerFigures(canevas, cercles, rectangles, triangles);
                break;
                
            default:
                cout << "La commande entree est invalide." << endl;
                break;
        }
        
        // On demande la commande a l'utilisateur
        cout << "Veuillez entrer une commande : " ;
        cin >> commande;
        cout << TRAIN + commande << endl;
        
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module permet d'ajouter une figure a sa liste respective. Soit
 un cercle, un rectangle ou un triangle.
 \param [in/out] cercles : Liste des cercles
 \param [in/out] rectangles : Liste des rectangles
 \param [in/out] triangles : Liste des triangles
 ----------------------------------------------------------------------- **/
void ajouter(vector<Cercle> &cercles, vector<Rectangle> &rectangles, vector<Triangle> &triangles)
{
    // Declaration des fonctions prototypes
    int obtenirType(bool);
    
    // Declaration des variables
    int type;
    
    type = obtenirType(true);
    
    switch (type)
    {
        case CERCLE:
        {
            Cercle unCercle;
            // Lecture des informations du cercle
            unCercle.lecture();
            
            // Ajout du cercle a la liste
            cercles.push_back(unCercle);
            
            break;
        }
        case RECTANGLE:
        {
            Rectangle unRectangle;
            // Lecture des informations du rectangle
            unRectangle.lecture();
            
            // Ajoutdu rectangle a la liste
            rectangles.push_back(unRectangle);
            
            break;
        }
        case TRIANGLE:
        {
            Triangle unTriangle;
            // Lecture des informations du triangle
            unTriangle.lecture();
            
            // Ajout du triangle a la liste
            triangles.push_back(unTriangle);
            
            break;
        }
        default:
            break;
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de retirer une figure a sa liste respective. Soit
 un cercle, un rectangle ou un triangle.
 \param [in/out] cercles : Liste des cercles
 \param [in/out] rectangles : Liste des rectangles
 \param [in/out] triangles : Liste des triangles
 ----------------------------------------------------------------------- **/
void retirer(vector<Cercle> &cercles, vector<Rectangle> &rectangles, vector<Triangle> &triangles)
{
    
    // Declaration des fonctions prototypes
    int obtenirType(bool);
    
    // Declaration des variables
    int type;
    int indice;
    
    type = obtenirType(true);
    indice = obtenirIndice(cercles, rectangles, triangles, type, true);
    
    switch (type)
    {
        case CERCLE:
        {
            // Suppression du cercle
            cercles.erase(cercles.begin() + indice);
            break;
        }
        case RECTANGLE:
        {
            // Suppression du rectangle
            rectangles.erase(rectangles.begin() + indice);
            break;
        }
        case TRIANGLE:
        {
            // Suppression du triangle
            triangles.erase(triangles.begin() + indice);
            break;
        }
        default:
            break;
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module permet d'obtenir le type de figure a manipuler. Soit
 un cercle, un rectangle ou un triangle.
 \param [in] afficherListe : Indique si on affiche ou non la liste des 
 choix possibles.
 ----------------------------------------------------------------------- **/
int obtenirType(bool afficherListe)
{
    int type;
    
    if (afficherListe)
    {
        cout << "Types disponibles : " << endl;
        cout << CERCLE << " " << " Cercle " << endl;
        cout << RECTANGLE << " " << " Rectangle " << endl;
        cout << TRIANGLE << " " << " Triangle " << endl << endl;
    }
    
    cout << "Veuillez choisir un type de figure : ";
    cin >> type;
    cout << TRAIN << type << endl;
    
    return type;
}

/** ----------------------------------------------------------------------
 \brief Ce module permet d'obtenir l'indice d'une figure patriculiere. Soit
 un cercle, un rectangle ou un triangle, dependament du type de figure en
 entree.
 \param [in] cercles : Liste des cercles
 \param [in] rectangles : Liste des rectangles
 \param [in] triangles : Liste des triangles
 \param [in] type : Type de la figure dont on veut recuperer l'indice
 \param [in] afficherListe : Indique si on affiche ou non la liste des
 indices possibles.
 ----------------------------------------------------------------------- **/
int obtenirIndice(vector<Cercle> &cercles, vector<Rectangle> &rectangles, vector<Triangle> &triangles, int type, bool afficherListe)
{
    
    // Declaration des fonctions prototype
    void listerFigures(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &, int);
    
    // Declaration des variables locales
    int indice;
    
    if (afficherListe)
    {
        switch (type)
        {
            case CERCLE:
                
                // Affichage de la liste de cercles
                listerFigures(cercles, rectangles, triangles, CERCLE);
                
                break;
            case RECTANGLE:
                
                // Affichage de la liste de rectangles
                listerFigures(cercles, rectangles, triangles, RECTANGLE);
                
                break;
            case TRIANGLE:
                
                // Affichage de la liste de rectangles
                listerFigures(cercles, rectangles, triangles, TRIANGLE);
                
                break;
                
            default:
                break;
        }
    }
    
    cout << "Veuillez choisir une figure : ";
    cin >> indice;
    cout << TRAIN << indice << endl;
    
    return indice;
}

/** ----------------------------------------------------------------------
 \brief Ce module permet d'afficher la liste de toutes les figures dessines
 a l'ecran.
 \param [in] cercles : Liste des cercles
 \param [in] rectangles : Liste des rectangles
 \param [in] triangles : Liste des triangles
 \param [in] type : Permet d'afficher une liste de figure specifique. 
 ex : seulement la liste des cercles. (0 par defaut - soit toutes les listes)
 ----------------------------------------------------------------------- **/
void listerFigures(vector<Cercle> &cercles, vector<Rectangle> &rectangles, vector<Triangle> &triangles, int type = 0)
{
    if (type == 0 || type == CERCLE)
    {
        cout << endl << "---------------" << endl;
        cout << "-- CERCLES" << endl;
        cout << "---------------" << endl;
        
        if (cercles.size() > 0) {
            for (int i = 0; i < cercles.size(); i++)
            {
                cout << "Cercle " << i << endl << cercles.at(i).enString();
            }
        }
        else
        {
            cout << "/!\\ La liste ne contient aucun cercle." << endl;
        }
    }
    
    if (type == 0 || type == RECTANGLE)
    {
        
        cout << endl << "---------------" << endl;
        cout << "-- RECTANGLES" << endl;
        cout << "---------------" << endl;
        
        if (rectangles.size() > 0) {
            for (int i = 0; i < rectangles.size(); i++)
            {
                cout << "Rectangle " << i << endl << rectangles.at(i).enString();
            }
        }
        else
        {
            cout << "/!\\ La liste ne contient aucun rectangle." << endl;
        }
    }
    
    if (type == 0 || type == TRIANGLE)
    {
        cout << endl << "---------------" << endl;
        cout << "-- TRIANGLES" << endl;
        cout << "---------------" << endl;
        
        if (triangles.size() > 0) {
            for (int i = 0; i < triangles.size(); i++)
            {
                cout << "Triangle " << i << endl << triangles.at(i).enString();
            }
        }
        else
        {
            cout << "/!\\ La liste ne contient aucun triangle." << endl;
        }
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module permet d'effectuer une rotation sur une figure.
 \param [in/out] cercles : Liste des cercles
 \param [in/out] rectangles : Liste des rectangles
 \param [in/out] triangles : Liste des triangles
 ----------------------------------------------------------------------- **/
void effectuerRotation (vector<Cercle> &cercles, vector<Rectangle> &rectangles, vector<Triangle> &triangles)
{

    // Declaration des fonctions prototypes
    int type = obtenirType(true);
    int indice = obtenirIndice(cercles, rectangles, triangles, type, true);
    float degreeEnRadians(int);
    
    int angle;
    float angleRadian;
    
    cout << "Angle de rotation : ";
    cin >> angle;
    cout << TRAIN << angle << endl;
    
    angleRadian = degreeEnRadians(angle);
    
    switch (type)
    {
        case RECTANGLE:
            
            // On effectu la rotation sur le rectangle
            rectangles.at(indice).effectuerRotation(angleRadian);
            
            break;
        case TRIANGLE:
            
            // On effectu la rotation sur le triangle
            triangles.at(indice).effectuerRotation(angleRadian);
            break;
            
        default:
            break;
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de deplacer une figure
 \param [in/out] cercles : Liste des cercles
 \param [in/out] rectangles : Liste des rectangles
 \param [in/out] triangles : Liste des triangles
 ----------------------------------------------------------------------- **/
void deplacer(vector<Cercle> &cercles, vector<Rectangle> &rectangles, vector<Triangle> &triangles)
{
    // Declaration des fonctions prototypes
    int type = obtenirType(true);
    int indice = obtenirIndice(cercles, rectangles, triangles, type, true);
    
    int deltaX;
    int deltaY;
    
    cout << "Deplacement en x : ";
    cin >> deltaX;
    cout << TRAIN << deltaX << endl;
    
    cout << "Deplacement en y : ";
    cin >> deltaY;
    cout << TRAIN << deltaY << endl;

    
    switch (type)
    {
        case CERCLE:
            
            // On effectu la rotation sur le cercle
            cercles.at(indice).deplacer(deltaX, deltaY);
            
            break;
        case RECTANGLE:
            
            // On effectu la rotation sur le rectangle
            rectangles.at(indice).deplacer(deltaX, deltaY);
            
            break;
        case TRIANGLE:
            
            // On effectu la rotation sur le triangle
            triangles.at(indice).deplacer(deltaX, deltaY);
            break;
            
        default:
            break;
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module permet de modifier la taille d'une figure
 \param [in/out] cercles : Liste des cercles
 \param [in/out] rectangles : Liste des rectangles
 \param [in/out] triangles : Liste des triangles
 ----------------------------------------------------------------------- **/
void modifierTaille(vector<Cercle> &cercles, vector<Rectangle> &rectangles, vector<Triangle> &triangles)
{
    // Declaration des fonctions prototypes
    int type = obtenirType(true);
    int indice = obtenirIndice(cercles, rectangles, triangles, type, true);
    Point pointCentral;
    float proportion;
    
    cout << "Point central de modification : ";
    pointCentral.lecture();
    cout << TRAIN;
    pointCentral.afficher();
    cout << endl;
    
    cout << "Proportion : ";
    cin >> proportion;
    cout << TRAIN << proportion << endl;
    
    switch (type)
    {
        case CERCLE:
            
            // On effectu la rotation sur le cercle
            cercles.at(indice).modifierTaille(pointCentral, proportion);
            
            break;
        case RECTANGLE:
            
            // On effectu la rotation sur le rectangle
            rectangles.at(indice).modifierTaille(pointCentral, proportion);
            
            break;
        case TRIANGLE:
            
            // On effectu la rotation sur le triangle
            triangles.at(indice).modifierTaille(pointCentral, proportion);
            break;
            
        default:
            break;
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module dessine toutes les figures sur le canevas
 \param [in/out] cercles : Liste des cercles
 \param [in/out] rectangles : Liste des rectangles
 \param [in/out] triangles : Liste des triangles
 ----------------------------------------------------------------------- **/
void dessinerFigures (Canevas canevas, vector<Cercle> &cercles, vector<Rectangle> &rectangles, vector<Triangle> &triangles)
{
    // On redessine toutes les figures sur le canvas
    for (int i = 0; i < cercles.size(); i++)
    {
        cercles.at(i).dessiner(canevas);
    }
    
    for (int i = 0; i < rectangles.size(); i++)
    {
        rectangles.at(i).dessiner(canevas);
    }
    
    for (int i = 0; i < triangles.size(); i++)
    {
        triangles.at(i).dessiner(canevas);
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module dessine toutes les figures sur le canevas
 \param [in] degree : Degree a convertir en radian
 \return degreeRadian : Resultat de la conversion de degree en radian
 ----------------------------------------------------------------------- **/
float degreeEnRadians(int degree)
{
    // Declaration des constantes
    const float PI = 3.1416;
    const int DIVISEUR = 180;
    
    // Declaration des variables
    float degreeRadian;
    
    // Conversion
    degreeRadian = degree * PI / DIVISEUR;
    
    return degreeRadian;
}