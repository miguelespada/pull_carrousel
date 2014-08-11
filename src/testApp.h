#pragma once

#include <ctime>
#include "ofMain.h"
#include "PrizeManager.h"
#include "Carrousel.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);

        PrizeManager prizeManager;
        Carrousel carrousel;
        bool has_prize = false;
};

