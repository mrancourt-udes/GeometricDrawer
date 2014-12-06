/** **************************************************************
 \file tp6.cpp
 \author Martin Rancourt - 140 59 412
 \author Guillaume Theaud - 131 97 685

 <b>Entrees:</b>
        \li (\c clavier)  commande a executer (\c caractere)
        \li (\c clavier)  type de la figure (\c entier)
        \li (\c clavier)  indice de la figure (\c entier)
        \li (\c clavier)  suite de point (\c point)
        \li (\c clavier)  rayon du cercle (\c entier)
        \li (\c clavier)  angle de rotation (\c entier)
        \li (\c clavier)  deplacement en x (\c entier)
        \li (\c clavier)  deplacement en y (\c entier)
        \li (\c clavier)  proportion (\c reel)

 <b>Sorties:</b>
        \li (\c medium) affichage des lignes formant le cercle (\c ligne)
        \li (\c medium) affichage des lignes formant le rectangle (\c ligne)
        \li (\c medium) affichage des lignes formant le triangle (\c ligne)

 \brief Ce logiciel sert a dessiner différentes figures comme
    un cercle, un triangle et un rectangle. On peut effectuer des
    modifications sur ces figures tel que la rotation,
    la modification de la taille et le deplacement.
 *****************************************************************/

#include <string>
#include <vector>

#include "canevas.h"
#include "Cercle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

// Declaration des fonctions prototypes globales
void listerFigures(vector<Cercle>, vector<Rectangle>, vector<Triangle>, int);
int obtenirIndice(vector<Cercle>, vector<Rectangle>, vector<Triangle>, int, bool);

// Declaration des constantes globales
const int CERCLE = 1;
const int RECTANGLE = 2;
const int TRIANGLE = 3;
const string TRAIN = ">> ";

/** ----------------------------------------------------------------------
 \brief Point d'entree du logiciel de dessin.
 ----------------------------------------------------------------------- **/
int main()
{
    // Declaration des fonctions prototypes
    void ajouter(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
    void retirer(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
    void effectuerRotation(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
    void deplacer(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
    void modifierTaille(vector<Cercle> &, vector<Rectangle> &, vector<Triangle> &);
    void dessinerFigures (Canevas &, vector<Cercle>, vector<Rectangle>, vector<Triangle>);

    // Declaration des constantes
    const char AJOUTER = 'a';
    const char LISTER = 'l';
    const char EFFACER = 'e';
    const char EFFECTUER_ROTATION = 'r';
    const char DEPLACER = 'd';
    const char MODIFIER_TAILLE = 't';
    const char QUITTER = 'q';

    // Declaration des variables
    char commande;
    Canevas canevas;
    vector<Cercle> cercles;
    vector<Rectangle> rectangles;
    vector<Triangle> triangles;

    // On demande la commande a l'utilisateur
    cout << "Veuillez entrer une commande : " ;
    cin >> commande;
    cout << TRAIN + commande << endl;

    // Tant que la sentinelle de terminaison de programme n'est pas atteinte
    while (commande != QUITTER)
    {
        // Selon la commande entree
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
                // Commande invalide
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

    // Obtention des donnees necessaire a l'ajout
    type = obtenirType(true);

    // Selon le type de la figure
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
            cout << "Erreur, le type de figure est inconnu!!";
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

    // Obtention des donnees necessaire a la suppression
    type = obtenirType(true);
    indice = obtenirIndice(cercles, rectangles, triangles, type, true);

    // Selon le type de la figure
    switch (type)
    {
        case CERCLE:
        
            // Suppression du cercle
            cercles.erase(cercles.begin() + indice);
            break;
        
        case RECTANGLE:
        
            // Suppression du rectangle
            rectangles.erase(rectangles.begin() + indice);
            break;
        
        case TRIANGLE:
        
            // Suppression du triangle
            triangles.erase(triangles.begin() + indice);
            break;
        
        default:
            cout << "Erreur, le type de figure est inconnu!!";
            break;
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module permet d'obtenir le type de figure a manipuler. Soit
 un cercle, un rectangle ou un triangle.
 \param [in] afficherListe : Indique si on affiche ou non la liste des
 choix possibles.
 \return type : type de figure
 ----------------------------------------------------------------------- **/
int obtenirType(bool afficherListe)
{
    // Declaration des variables
    int type;

    // Si on veut afficher la liste des choix possible
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
 \return indice : indice de la figure
 ----------------------------------------------------------------------- **/
int obtenirIndice(vector<Cercle> cercles, vector<Rectangle> rectangles, vector<Triangle> triangles, int type, bool afficherListe)
{
    // Declaration des variables locales
    int indice;

    // Si on veut afficher la liste des figures
    if (afficherListe)
    {
        // Selon le type de la figure
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
                cout << "Erreur, le type de figure est inconnu!!";
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
void listerFigures(vector<Cercle> cercles, vector<Rectangle> rectangles, vector<Triangle> triangles, int type = 0)
{
    // Si le type n'est pas specifie ou si le type est 1 (cercle)
    if (type == 0 || type == CERCLE)
    {
        cout << endl << "---------------" << endl;
        cout << "-- CERCLES" << endl;
        cout << "---------------" << endl;

        if (cercles.size() > 0)
        {
            for (unsigned int i = 0; i < cercles.size(); i++)
            {
                cout << "Cercle " << i << endl << cercles.at(i).enString();
            }
        }
        else
        {
            cout << "/!\\ La liste ne contient aucun cercle." << endl;
        }
    }

    // Si le type n'est pas specifie ou si le type est 2 (rectangle)
    if (type == 0 || type == RECTANGLE)
    {

        cout << endl << "---------------" << endl;
        cout << "-- RECTANGLES" << endl;
        cout << "---------------" << endl;

        if (rectangles.size() > 0)
        {
            for (unsigned int i = 0; i < rectangles.size(); i++)
            {
                cout << "Rectangle " << i << endl << rectangles.at(i).enString();
            }
        }
        else
        {
            cout << "/!\\ La liste ne contient aucun rectangle." << endl;
        }
    }

    // Si le type n'est pas specifie ou si le type est 3 (triangle)
    if (type == 0 || type == TRIANGLE)
    {
        cout << endl << "---------------" << endl;
        cout << "-- TRIANGLES" << endl;
        cout << "---------------" << endl;

        if (triangles.size() > 0)
        {
            for (unsigned int i = 0; i < triangles.size(); i++)
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

    // Declaration des variables
    int angle;
    float angleRadian;
    Point pointCentral;

    // Lecture du point de rotation
    cout << "Entrer le point central de rotation : ";
    pointCentral.lecture();
    // Lecture de l'angle de rotation (en degrees)
    cout << "Angle de rotation : ";
    cin >> angle;
    cout << TRAIN << angle << endl;

    // Conversion des degrees en radians
    angleRadian = degreeEnRadians(angle);

    // Selon le type de la figure
    switch (type)
    {
        case CERCLE:
            // La rotation sur le cercle est inutile.
            // On verifie quand meme pour eviter d'avoir une erreur de type inconnu.
            break;

        case RECTANGLE:

            // On effectu la rotation sur le rectangle
            rectangles.at(indice).effectuerRotation(pointCentral, angleRadian);

            break;
        case TRIANGLE:

            // On effectu la rotation sur le triangle
            triangles.at(indice).effectuerRotation(pointCentral, angleRadian);
            break;

        default:
            cout << "Erreur, le type de figure est inconnu!!";
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

    // Declaration des variables
    int deltaX;
    int deltaY;

    // Lecture des du deplacement en x et y
    cout << "Deplacement en x : ";
    cin >> deltaX;
    cout << TRAIN << deltaX << endl;

    cout << "Deplacement en y : ";
    cin >> deltaY;
    cout << TRAIN << deltaY << endl;

    // Selon le type de la figure
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
            cout << "Erreur, le type de figure est inconnu!!";
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

    // Lecture du point central de modification
    cout << "Point central de modification : ";
    pointCentral.lecture();
    cout << TRAIN;
    pointCentral.afficher();
    cout << endl;

    // Lecture de la proportion
    cout << "Proportion : ";
    cin >> proportion;
    cout << TRAIN << proportion << endl;

    // Selon le type de la figure
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
            cout << "Erreur, le type de figure est inconnu!!";
            break;
    }
}

/** ----------------------------------------------------------------------
 \brief Ce module dessine toutes les figures sur le canevas
 \param [in] cercles : Liste des cercles
 \param [in] rectangles : Liste des rectangles
 \param [in] triangles : Liste des triangles
 \param [in/out] canevas : canevas de dessin
 ----------------------------------------------------------------------- **/
void dessinerFigures (Canevas &canevas, vector<Cercle> cercles, vector<Rectangle> rectangles, vector<Triangle> triangles)
{
    // On redessine toutes les figures sur le canvas
    for (unsigned int i = 0; i < cercles.size(); i++)
    {
        cercles.at(i).dessiner(canevas);
    }

    for (unsigned int i = 0; i < rectangles.size(); i++)
    {
        rectangles.at(i).dessiner(canevas);
    }

    for (unsigned int i = 0; i < triangles.size(); i++)
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
