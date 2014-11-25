//
//  Cercle.cpp
//  tp6
//
//  Created by Martin Rancourt on 2014-11-24.
//  Copyright (c) 2014 Martin Racnourt. All rights reserved.
//

#include "Cercle.h"

// Constructeur par defaut
Cercle::Cercle() {
    
}

// Lectures des informations du cercle
void Cercle::lecture()
{
    Point pointCentral;
    
    // A refactoriser : Mettre dans la classe cercle::lecture()
    cout << "Point central : ";
    pointCentral.lecture();
    
    cout << "Rayon : ";
    cin >> rayon;
}

string Cercle::toString()
{
    string str =
    "Point central : (" + to_string(pointCentral.valX()) + "," + to_string(pointCentral.valY()) + ") \n" +
    "Rayon : " + to_string(rayon) + "\n";
    
    return str;
}