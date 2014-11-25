//
//  Cercle.h
//  tp6
//
//  Created by Martin Rancourt on 2014-11-24.
//  Copyright (c) 2014 Martin Racnourt. All rights reserved.
//

#ifndef __CERCLE_H_
#define __CERCLE_H_

#include <stdio.h>
#include <string>

#include "Point.h"

using namespace std;

class Cercle
{
    Point pointCentral;
    float rayon;
    
public:
    // Constructeurs
    Cercle();
    Cercle(Point, float);
    
    // Pour lecture
    void lecture();
    
    // Conversion de l'objet en string
    string toString();
};

#endif /* defined(__CERCLE_H_) */
