/** **************************************************************
 \file tp6.cpp
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685
 \brief TODO : resume
 *****************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "Cercle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

// Declaration des fonctions prototypes globales
void ajouter(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
void listerFigures(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
void listerFigures(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &, int);
void retirer(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
void effectuerRotation ();
void deplacer();
void modifierTaille();

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
const string TYPE_CERCLE = "Cercle";
const string TYPE_RECTANGLE = "Rectangle";
const string TYPE_TRIANGLE = "Triangle";
const string TRAIN = ">> ";

int main()
{
    char commande;
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
                break;
            case LISTER:
                // Lister les figures
                listerFigures(cercles, rectangles, triangles, 0);
                break;
                
            case EFFACER:
                // Supprimer une figure
                retirer(cercles, rectangles, triangles);
                break;
                
            case EFFECTUER_ROTATION:
                // Effectuer une rotation sur une figure
                effectuerRotation();
                break;
                
            case DEPLACER:
                // Deplacer une figure
                deplacer();
                break;
                
            case MODIFIER_TAILLE:
                // Modifier la taille d'une figure
                modifierTaille();
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

void ajouter(vector<Cercle> &cercles, vector<Rectangle> &rectangles, vector<Triangle> &triangles)
{
    // Declaration des fonctions prototypes
    int obtenirType(bool);
    int obtenirIndice(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &, int, bool);
    
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

void retirer(vector<Cercle> &cercles, vector<Rectangle> &rectangles, vector<Triangle> &triangles)
{
    
    // Declaration des fonctions prototypes
    int obtenirType(bool);
    int obtenirIndice(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &, int, bool);
    
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
                cout << "Cercle " << i << endl << cercles.at(i).toString();
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
                cout << "Rectangle " << i << endl << rectangles.at(i).toString();
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
                cout << "Triangle " << i << endl << triangles.at(i).toString();
            }
        }
        else
        {
            cout << "/!\\ La liste ne contient aucun triangle." << endl;
        }
    }
}

void effectuerRotation ()
{
    // TODO : implementer la rotation de figures
}

void deplacer()
{
    // TODO : implementer le deplacement de figures
}

void modifierTaille()
{
    // TODO : implementer la modification de taille
}