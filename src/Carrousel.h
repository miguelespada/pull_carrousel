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
#include "prize.h"

#include "SettingsManager.h"
#include "AssetsManager.h"

class Carrousel{
public:

    void start(string prize);
    void draw();
    void draw_winning(string prize);
    void draw_rules();
    void update();
    bool has_stopped();
    SettingsManager settings;
    AssetsManager assets;
    
private:
    
    void draw_background();
    void draw_background_art();
    void draw_masks();
    void draw_carrousel();
    void draw_prize(prize p);
    void fill_carrousel(string prize);
    void compute_carrousel();
    void update_speed();
    
    float time, prize_x, speed;
    vector<prize> carrousel;
    
};



#endif /* defined(__pull_carrousel__Carrousel__) */
