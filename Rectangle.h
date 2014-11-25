//
//  Rectangle.h
//  tp6
//
//  Created by Martin Rancourt on 2014-11-22.
//  Copyright (c) 2014 Martin Racnourt. All rights reserved.
//

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include <stdio.h>
#include <string>

#include "Point.h"

class Rectangle
{
    Point point1;
    Point point2;
    
public:
    // Constructeurs
    Rectangle();
    Rectangle(Point, Point);
    
    // Pour lecture
    void lecture();
    
    // Conversion de l'objet en string
    string toString();
};

#endif /* defined(__RECTANGLE_H__) */
