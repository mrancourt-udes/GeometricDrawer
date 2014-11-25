//
//  Triangle.h
//  tp6
//
//  Created by Martin Rancourt on 2014-11-22.
//  Copyright (c) 2014 Martin Racnourt. All rights reserved.
//

#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <stdio.h>
#include <string>

#include "Point.h"

class Triangle
{
    // Membres prives
    Point point1;
    Point point2;
    Point point3;
    
    // Methodes publiques
    public:
    
    // Constructeurs
    Triangle();
    Triangle(Point, Point, Point);
    
    // Pour lecture
    void lecture();
    
    void setCoordonnees(Point, Point, Point);
    void dessiner();
    
    // Conversion de l'objet en string
    string toString();
    
};

#endif /* defined(__TRIANGLE_H__) */
