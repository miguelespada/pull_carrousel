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
    
    carrousel.draw();

    carrousel.update();
    
    if(carrousel.has_stopped() && has_prize){
        prizeManager.disable_current_prize();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'a':
            cout << "Time to next prize: " << prizeManager.seconds_to_next_prize() << " s" << endl;
            break;
        case ' ':
            if(prizeManager.is_prize_enabled()){
                string prize = prizeManager.get_current_prize();
                cout << "Next prize is: " << prize << endl;
                carrousel.start(prize);
                has_prize = true;
                
            }
            else{
                cout << "Next prize is: " << "nothing" << endl;
                carrousel.start("nothing");
                has_prize = false;
            }
            
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

