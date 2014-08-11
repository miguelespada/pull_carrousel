//
//  Carrousel.cpp
//  pull_carrousel
//
//  Created by miguel valero espada on 8/10/14.
//
//

#include "Carrousel.h"
#define PRIZE_NUMBER 9

#define SETTINGS_FILE "/Users/miguel/Desktop/settings.json"

string prize_names[] = {"skate", "bicicleta", "ipad",
                        "gopro","impresora", "gafas",
                        "auriculares", "descuento", "nothing"};

Carrousel::Carrousel(){
    settings.open(SETTINGS_FILE);
    assets_path = settings["assets"].asString();
    width = settings["width"].asInt();
    height = settings["height"].asInt();
    icon_width = settings["icon"].asInt();
    cout << "Resolution: " << width << " x " << height << endl;
    cout << "Assets folder: " << assets_path << endl;
    
    load_prizes();
    background.loadImage(assets_path + "background.png");
    portal.loadImage(assets_path + "portal.png");
}

int Carrousel::icon_size(){
    return icon_width;
}

int Carrousel::screen_width(){
    return width;
}

int Carrousel::screen_height(){
    return height;
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
    draw_background();
    draw_carrousel();
    draw_background_art();
    draw_masks();
}

void Carrousel::draw_background(){
    ofBackground(255, 0, 123);
}

void Carrousel::draw_masks(){
    ofSetColor(255, 0, 123, 200);
    
    ofRect(0,
           screen_height()/2  - icon_size()/2 ,
           screen_width()/2 - icon_size()/2 - 4,
           icon_size() );
    
    ofRect(screen_width()/2 + icon_size()/2 +  5 ,
           screen_height()/2  - icon_size()/2,
           screen_width(),
           icon_size());
    
}

void Carrousel::draw_background_art(){
    background.draw(0, 0);
    portal.draw(0, 0);
}

void Carrousel::draw_prize(prize p){
    ofSetColor(255, 255, 255);
    ofPushMatrix();
    ofTranslate(screen_width()/2 - icon_size()/2, 0);
    prize_images[p.prize_name].draw(p.x, screen_height() / 2 - icon_size() / 2  );
    ofPopMatrix();
    
    if(abs(p.x) < 45)
        prize_captions[p.prize_name].draw(0, 0);    
}


void Carrousel::draw_carrousel(){
    for (std::vector<prize>::iterator it = carrousel.begin() ; it != carrousel.end(); ++it){
        draw_prize(*it);
        if (time > 0) (*it).x += speed;
    }
}

bool Carrousel::has_stopped(){
    return time == 0;
}

void Carrousel::load_prizes(){
    for(int i = 0; i < PRIZE_NUMBER; i++){
        string filename = assets_path + "icons/" + prize_names[i] + ".png";
        prize_images[prize_names[i]]
        .loadImage( filename );
        cout << "Loading: " << filename << endl;
        filename = assets_path + "names/" + prize_names[i] + ".png";
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
    
    prize_x = -speed *
             (pow(decay, exp_time) - 1)/ (decay - 1)
            - linear_time * speed;
    
    time = exp_time + linear_time;
};

void Carrousel::fill_carrousel(string prize_name){
    carrousel.clear();
    for(int i = 1; i < 5; i ++)
        carrousel.push_back(prize(prize_x - icon_size() * i,
        prize_names[int(ofRandom(PRIZE_NUMBER))]));
    
    carrousel.push_back(prize(prize_x, prize_name));
    
    int xx = prize_x + icon_size();
    while(xx < icon_size() * 4){
        carrousel.push_back(prize(xx, prize_names[int(ofRandom(PRIZE_NUMBER))]));
        xx += icon_size();
    }
}