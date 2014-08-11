#include "testApp.h"


//--------------------------------------------------------------        
void testApp::setup(){
    
    background.loadImage("/Users/miguel/Desktop/pull/background.png");
    portal.loadImage("/Users/miguel/Desktop/pull/portal.png");
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    carrousel.load_prizes();
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(255, 0, 123);
    
    ofSetColor(255, 255, 255);
    
    carrousel.draw();
    background.draw(0, 0);
    portal.draw(0, 0);
    
    ofSetColor(255, 0, 123, 200);
    ofRect(0,
           ofGetHeight()/2  - carrousel.icon_size()/2 ,
           ofGetWidth()/2 - carrousel.icon_size()/2 - 4,
           carrousel.icon_size() );
    
    ofRect(ofGetWidth()/2 + carrousel.icon_size()/2 +  5 ,
           ofGetHeight()/2  - carrousel.icon_size()/2,
           ofGetWidth(),
           carrousel.icon_size());
    
    carrousel.update();
    
    if(carrousel.has_stopped()){
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
                
            }
            else{
                cout << "No prize :(" << endl;
                carrousel.start("nothing");
            }
            
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

