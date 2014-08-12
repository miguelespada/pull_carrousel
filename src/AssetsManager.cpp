//
//  AssetsManager.cpp
//  pull_carrousel
//
//  Created by miguel valero espada on 8/12/14.
//
//

#include "AssetsManager.h"

#define PRIZE_NUMBER 9

string prize_names[PRIZE_NUMBER] = {"skate", "bicicleta", "ipad",
    "gopro","impresora", "gafas",
    "auriculares", "descuento", "nothing"};


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
        string filename = assets_path + "rules/rule_" + ofToString(i) + ".png";
        rules[i].loadImage(filename);
        cout << "Loading: " << filename << endl;
    }
    for(int i = 0; i < 2; i ++){
        string filename = assets_path + "rules/animation_" + ofToString(i) + ".png";
        background_animations[i].loadImage(filename);
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

void AssetsManager::draw_rules(){
    rules[rule_index].draw(0, 0);
    background_animations[animation_index].draw(0, 0);
    
    
    if(ofGetFrameNum() % 300 == 0)
        rule_index = (rule_index + 1) % 3;
    if(ofGetFrameNum() % 20 == 0)
        animation_index = (animation_index + 1) % 2;
    
}

void AssetsManager::draw_background_art(){
    background.draw(0, 0);
    portal.draw(0, 0);
    portal_animations[portal_animation_index].draw(0, 0);

    if(ofGetFrameNum() % 60 == 0)
        portal_animation_index = (portal_animation_index + 1) % 2;
}