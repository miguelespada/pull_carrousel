//
//  prize.h
//  pull_carrousel
//
//  Created by miguel valero espada on 8/10/14.
//
//

#ifndef __pull_carrousel__prize__
#define __pull_carrousel__prize__

#include <iostream>

class prize{
public:
    prize(float _x, string _name){
        prize_name = _name;
        x = _x;
    }
    float x;
    string prize_name;
};

#endif /* defined(__pull_carrousel__prize__) */
