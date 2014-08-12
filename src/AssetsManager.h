//
//  AssetsManager.h
//  pull_carrousel
//
//  Created by miguel valero espada on 8/12/14.
//
//

#ifndef __pull_carrousel__AssetsManager__
#define __pull_carrousel__AssetsManager__

#include <iostream>
#include "ofMain.h"


class AssetsManager{
public:
    void load(string assets_path);
    string random_prize();
    void draw_rules();
    void draw_background_art();
    void draw_winning(string prize);
    
    std::map<std::string, ofImage> prize_images, prize_captions, prize_winnings;
    ofImage background_animations[2], portal_animations[2];
    ofImage background, portal;
    
private:
    ofImage rules[3];
    int rule_index = 0,
    animation_index = 0,
    portal_animation_index = 0;
        
};
#endif /* defined(__pull_carrousel__AssetsManager__) */
