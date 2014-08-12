//
//  SettingsManager.h
//  pull_carrousel
//
//  Created by miguel valero espada on 8/12/14.
//
//

#ifndef __pull_carrousel__SettingsManager__
#define __pull_carrousel__SettingsManager__

#include <iostream>
#include "ofxJSON.h"
#include "ofMain.h"

class SettingsManager{
public:
    void load();
    int exp_time, linear_time;
    float speed, decay;
    int width, height, icon_size;
    int sleep_time;
    string assets_path;
    
    int back_colors[10];
    void randomize_color();
    ofColor get_current_color();
    
    
private:
    ofxJSONElement settings;
    int current_color = 0;
};

#endif /* defined(__pull_carrousel__SettingsManager__) */
