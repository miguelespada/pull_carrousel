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
    Carrousel();

    void load_prizes();
    void start(string prize);
    void draw();
    void update();
    int screen_width();
    int screen_height();
    int icon_size();
    bool has_stopped();
    
private:
    
    void draw_background();
    void draw_background_art();
    void draw_masks();
    void draw_carrousel();
    void draw_prize(prize p);
    void fill_carrousel(string prize);

    void compute_carrousel();
    ofxJSONElement settings;
    int exp_time, linear_time;
    float speed, decay, time, prize_x;
    vector<prize> carrousel;
    std::map<std::string, ofImage> prize_images;
    std::map<std::string, ofImage> prize_captions;
    int width, height, icon_width;
    string assets_path;
    ofImage background, portal;
    
};



#endif /* defined(__pull_carrousel__Carrousel__) */
