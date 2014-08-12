#pragma once

#include <ctime>
#include "ofMain.h"
#include "PrizeManager.h"
#include "Carrousel.h"
#include "ofxOsc.h"

#define PORT 8000

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
    
    void launchGame();
    void pushButton();
    void parseOsc();
    
    PrizeManager prizeManager;
    Carrousel carrousel;
    
    string prize;
    int state = 0;
    unsigned long long timer;
    
    ofxOscReceiver receiver;
};

