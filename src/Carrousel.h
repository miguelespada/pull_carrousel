//
//  Carrousel.h
//  pull_carrousel
//
//  Created by miguel valero espada on 8/10/14.
//
//

#ifndef __pull_carrousel__Carrousel__
#define __pull_carrousel__Carrousel__

#include <iostream>
#include "ofMain.h"
#include "ofxJSON.h"
#include "prize.h"

class Carrousel{
public:
    void load_prizes();
    void start(string prize);
    void draw();
    void update();
    float screen_center();
    float icon_size();
    bool has_stopped();
    
    
private:
    void fill_carrousel(string prize);
    void compute_carrousel();
    
    ofxJSONElement settings;
    int exp_time, linear_time;
    float speed, decay, time, prize_x;
    vector<prize> carrousel;
    std::map<std::string, ofImage> prize_images;
    std::map<std::string, ofImage> prize_captions;
};



#endif /* defined(__pull_carrousel__Carrousel__) */
