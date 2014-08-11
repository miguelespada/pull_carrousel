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
    void randomize_color();
    int screen_width();
    int screen_height();
    int icon_size();
    bool has_stopped();
    
    void draw_winning(string prize);
    void draw_rules();
    
private:
    
    void draw_background();
    void draw_background_art();
    void draw_masks();
    void draw_carrousel();
    void draw_prize(prize p);
    void fill_carrousel(string prize);

    void compute_carrousel();
    ofColor get_current_color();
    
    ofxJSONElement settings;
    int exp_time, linear_time;
    float speed, decay, time, prize_x;
    vector<prize> carrousel;
    
    std::map<std::string, ofImage> prize_images, prize_captions, prize_winnings;
    ofImage rules[3];
    ofImage background_animations[2];
    
    int width, height, icon_width;
    string assets_path;
    ofImage background, portal;
    int current_color = 0;
    
    int rule_index = 0;
    int animation_index = 0;
};



#endif /* defined(__pull_carrousel__Carrousel__) */
