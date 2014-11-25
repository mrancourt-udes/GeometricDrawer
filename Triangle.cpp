//
//  Triangle.cpp
//  tp6
//
//  Created by Martin Rancourt on 2014-11-22.
//  Copyright (c) 2014 Martin Racnourt. All rights reserved.
//

#include "Triangle.h"

Triangle::Triangle()
{
    
}

// Lectures des informations du rectangle
void Triangle::lecture()
{
    Point point1;
    Point point2;
    Point point3;
    
    // A refactoriser : Mettre dans la classe cercle::lecture()
    cout << "Point 1 : ";
    point1.lecture();
    
    cout << "Point 2 : ";
    point2.lecture();
    
    cout << "Point 3 : ";
    point2.lecture();
    
}

string Triangle::toString()
{
    string str =
    "Point 1 : (" + to_string(point1.valX()) + "," + to_string(point1.valY()) + ") \n" +
    "Point 2 : (" + to_string(point1.valX()) + "," + to_string(point2.valY()) + ") \n" +
    "Point 3 : (" + to_string(point2.valX()) + "," + to_string(point3.valY()) + ") \n";
    
    return str;
}