//
//  AssetsManager.cpp
//  pull_carrousel
//
//  Created by miguel valero espada on 8/12/14.
//
//

#include "AssetsManager.h"


void AssetsManager::load(string assets_path){
    
    
    background.loadImage(assets_path + "background.png");
    portal.loadImage(assets_path + "portal.png");
    
    for(int i = 0; i < PRIZE_NUMBER; i++){
        string filename = assets_path + "../icons/" + prize_names[i] + ".png";
        prize_images[prize_names[i]].loadImage( filename );
        cout << "Loading: " << filename << endl;
        filename = assets_path + "names/" + prize_names[i] + ".png";
        prize_captions[prize_names[i]].loadImage( filename );
        cout << "Loading: " << filename << endl;
        filename = assets_path + "win/" + prize_names[i] + ".png";
        prize_winnings[prize_names[i]].loadImage(filename);
        cout << "Loading: " << filename << endl;
    }
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 4; j ++){
            string filename = assets_path + "rules/rule-" + ofToString(i) + "-" + ofToString(j) + ".png";
            rules[i][j].loadImage(filename);
            cout << "Loading: " << filename << endl;
        }
    }
    for(int i = 0; i < 2; i ++){
        string filename = assets_path + "rules/animation_" + ofToString(i) + ".png";
        background_animations[i].loadImage(filename);
        cout << "Loading: " << filename << endl;
    }
    
    for(int i = 0; i < 3; i ++){
        string filename = assets_path + "rules/rules_background-" + ofToString(i) + ".png";
        rules_background[i].loadImage(filename);
        cout << "Loading: " << filename << endl;
    }
    
    for(int i = 0; i < 2; i ++){
        string filename = assets_path + "portal_animation_" + ofToString(i) + ".png";
        portal_animations[i].loadImage(filename);
        cout << "Loading: " << filename << endl;
    }
}

string AssetsManager::random_prize(){
    return prize_names[int(ofRandom(PRIZE_NUMBER))];
}


void AssetsManager::draw_background_art(){
    background.draw(0, 0);
    portal.draw(0, 0);
    portal_animations[portal_animation_index].draw(0, 0);

    if(ofGetFrameNum() % 60 == 0)
        portal_animation_index = (portal_animation_index + 1) % 2;
}

void AssetsManager::draw_winning(string prize){
    prize_winnings[prize].draw(0, 0);
}

void AssetsManager::next_rule_language(){
    rule_language = (rule_language + 1) % 3;
    rule_index = 0;
}