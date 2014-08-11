#include "testApp.h"


//--------------------------------------------------------------        
void testApp::setup(){
    
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){

    switch (state) {
        case 0:
            carrousel.draw_rules();
            break;
        case 1:
            carrousel.draw();
            
            carrousel.update();
            
            if(carrousel.has_stopped()){
                if(prize != "nothing")
                    prizeManager.disable_current_prize();
                state = 2;
                ofSleepMillis(1500);
            }
            break;
        case 2:
            carrousel.draw_winning(prize);
            break;
        default:
            break;
    }
    
}
void testApp::launchGame(){
    if(prizeManager.is_prize_enabled())
        prize = prizeManager.get_current_prize();
    else
        prize = "nothing";
    
    cout << "Next prize is: " << prize << endl;
    carrousel.start(prize);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'a':
            cout << "Time to next prize: " << prizeManager.seconds_to_next_prize() << " s" << endl;
            break;
        case ' ':
            switch (state) {
                case 0:
                    launchGame();
                    state ++;
                    break;
                case 1:
                    state --;
                    break;
                case 2:
                    state = 0;
                    break;
                default:
                    break;
            }
            
            break;
        case 'c':
            carrousel.randomize_color();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

