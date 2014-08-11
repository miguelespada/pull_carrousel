//
//  Carrousel.cpp
//  pull_carrousel
//
//  Created by miguel valero espada on 8/10/14.
//
//

#include "Carrousel.h"

#define ICON_SIZE 180
#define PRIZE_NUMBER 9

#define SETTINGS_FILE "/Users/miguel/Desktop/settings.json"

string prize_names[] = {"skate", "bicicleta", "ipad",
    "gopro","impresora", "gafas",
    "auriculares", "descuento", "nothing"};

float Carrousel::icon_size(){
    return ICON_SIZE ;
}

void Carrousel::update(){
    if(time > 0){
        prize_x += speed;
        
        if(time < exp_time)
            speed *= decay;
        
        time -= 1;
        
        if(time == 0)
            speed = 0;
        
        if(abs(prize_x) < 1){
            time = 0;
        }

    }
}
void Carrousel::draw(){
    
    ofSetColor(255, 255, 255);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2 - ICON_SIZE/2, 0);
    for (std::vector<prize>::iterator it = carrousel.begin() ; it != carrousel.end(); ++it){
        prize_images[(*it).prize_name].draw((*it).x, ofGetHeight() / 2 - ICON_SIZE / 2  );
        
        ofPushMatrix();
        ofTranslate(- ofGetWidth()/2 + ICON_SIZE/2, 0);
        if(abs((*it).x) < 45)
            prize_captions[(*it).prize_name].draw(0, 0);
        ofPopMatrix();
        
        if (time > 0) (*it).x += speed;
        
    }
    ofPopMatrix();
}

bool Carrousel::has_stopped(){
    return time == 0;
}

void Carrousel::load_prizes(){
    string root = "/Users/miguel/Desktop/pull/";
    for(int i = 0; i < PRIZE_NUMBER; i++){
        string filename = root + "icons/" + prize_names[i] + ".png";
        prize_images[prize_names[i]]
        .loadImage( filename );
        cout << "Loading: " << filename << endl;
        filename = root + "names/" + prize_names[i] + ".png";
        prize_captions[prize_names[i]]
        .loadImage( filename );
    }
}

void Carrousel::start(string prize){
    compute_carrousel();
    fill_carrousel(prize);
}

void Carrousel::compute_carrousel(){
    
    bool parsingSuccessful = settings.open(SETTINGS_FILE);
    
    speed = settings["speed"].asInt();
    decay = settings["decay"].asFloat();
    exp_time = settings["exponential_time"].asInt();
    linear_time = settings["linear_time"].asInt();
    cout << "Speed: " << speed << endl;
    cout << "Decay: " << decay << endl;
    cout << "Exponential time: " << exp_time << endl;
    cout << "Linear time: " << linear_time << endl;

    
    prize_x = -speed *
             (pow(decay, exp_time) - 1)/ (decay - 1)
            - linear_time * speed;
    
    time = exp_time + linear_time;
};

void Carrousel::fill_carrousel(string prize_name){
    carrousel.clear();
    for(int i = 1; i < 5; i ++)
        carrousel.push_back(prize(prize_x - ICON_SIZE * i,
        prize_names[int(ofRandom(PRIZE_NUMBER))]));
    
    carrousel.push_back(prize(prize_x, prize_name));
    
    int xx = prize_x + ICON_SIZE;
    while(xx < ICON_SIZE * 4){
        carrousel.push_back(prize(xx, prize_names[int(ofRandom(PRIZE_NUMBER))]));
        xx += ICON_SIZE;
    }
}