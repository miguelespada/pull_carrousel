//
//  Carrousel.cpp
//  pull_carrousel
//
//  Created by miguel valero espada on 8/10/14.
//
//

#include "Carrousel.h"

void Carrousel::update_speed(){
    prize_x += speed;
    
    if(time < settings.exp_time)
        speed *= settings.decay;
    
    time -= 1;
    
    if(time == 0)
        speed = 0;
    
    if(abs(prize_x) < 1){
        time = 0;
    }
}

void Carrousel::update(){
    if(time > 0)
        update_speed();
}

void Carrousel::draw(){
    draw_background();
    draw_carrousel();
    draw_masks();
    ofSetColor(255);
    draw_background_art();
}

void Carrousel::draw_rules(){
    ofSetColor(255);
    draw_background();
    assets.rules_background[assets.rule_language].draw(0,0);
    assets.rules[assets.rule_language][assets.rule_index].draw(0, 0);
    assets.background_animations[assets.animation_index].draw(0, 0);
    if(settings.width == 960)
        assets.prize_images[assets.prize_names[assets.rule_prize]].draw(754 - 90 , 180 - 90);
    else
        assets.prize_images[assets.prize_names[assets.rule_prize]].draw(200 ,100);
    
    int pace = 10;
    if(ofGetFrameNum() % pace == 0){
        assets.animation_index = (assets.animation_index + 1) % 2;
    }
    
    if(ofGetFrameNum() % (4 * pace) == 0){
        assets.rule_prize = (assets.rule_prize + 1) % 8;
    }
    
    
    if(ofGetFrameNum() % (8 * pace) == 0){
        assets.rule_index = (assets.rule_index + 1) % 4;
        settings.randomize_color();
    }
    
    
}

void Carrousel::draw_winning(string prize){
    ofSetColor(255);
    draw_background();
    assets.draw_winning(prize);
}

void Carrousel::draw_background(){
    ofBackground(settings.get_current_color());
}


void Carrousel::draw_masks(){
    ofSetColor(settings.get_current_color(), 200);
    
    ofRect(0,
           settings.height/2  - settings.icon_size/2 ,
           settings.width/2 - settings.icon_size/2 - 4,
           settings.icon_size );
    
    ofRect(settings.width/2 +  settings.icon_size/2 +  5 ,
           settings.height/2  - settings.icon_size/2,
           settings.width,
           settings.icon_size);
}

void Carrousel::draw_background_art(){
    assets.draw_background_art();
}

void Carrousel::draw_prize(prize p){
    ofSetColor(255, 255, 255);
    ofPushMatrix();
    ofTranslate(settings.width/2 - settings.icon_size/2, 0);
    assets.prize_images[p.prize_name].draw(p.x, settings.height / 2 - settings.icon_size / 2  );
    ofPopMatrix();
    
    if(abs(p.x) < 45)
        assets.prize_captions[p.prize_name].draw(0, 0);
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


void Carrousel::start(string prize){
    compute_carrousel();
    fill_carrousel(prize);
}

void Carrousel::compute_carrousel(){
    prize_x = -settings.speed *
             (pow(settings.decay, settings.exp_time) - 1)/ (settings.decay - 1)
            - settings.linear_time * settings.speed;
    
    time = settings.exp_time + settings.linear_time;
    speed = settings.speed;
};

void Carrousel::fill_carrousel(string prize_name){
    carrousel.clear();
    
    for(int i = 1; i < 5; i ++)
        carrousel.push_back(prize(prize_x - settings.icon_size * i,
        assets.random_prize()));
    
    carrousel.push_back(prize(prize_x, prize_name));
    
    int xx = prize_x + settings.icon_size;
    while(xx < settings.icon_size * 4){
        carrousel.push_back(prize(xx, assets.random_prize()));
        xx += settings.icon_size;
    }
}