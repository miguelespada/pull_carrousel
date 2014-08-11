//
//  PrizeManager.h
//  pull_carrousel
//
//  Created by miguel valero espada on 8/9/14.
//
//

#ifndef __pull_carrousel__PrizeManager__
#define __pull_carrousel__PrizeManager__

#include <iostream>

#include <ctime>
#include "ofMain.h"
#include "ofxJSON.h"
#include "prize.h"


class PrizeManager{
public:
    string present_time();
    int next_prize();
    bool is_prize_enabled();
    void disable_current_prize();
    string get_current_prize();
    int seconds_to_next_prize();
    
    void start_carrousel();
    void load_prizes();
    
private:
    ofxJSONElement prizes;
    int currentPrizeIndex = -1;
    string current_prize;
};

#endif /* defined(__pull_carrousel__PrizeManager__) */
