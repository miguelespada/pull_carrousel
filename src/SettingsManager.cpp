//
//  SettingsManager.cpp
//  pull_carrousel
//
//  Created by miguel valero espada on 8/12/14.
//
//

#include "SettingsManager.h"


void SettingsManager::load(){
    settings.open(ofToDataPath("settings.json"));
    
    speed = settings["speed"].asInt();
    decay = settings["decay"].asFloat();
    exp_time = settings["exponential_time"].asInt();
    linear_time = settings["linear_time"].asInt();
    
    width = settings["width"].asInt();
    height = settings["height"].asInt();
    icon_size = settings["icon"].asInt();
    sleep_time = settings["sleep"].asInt();
    
    assets_path = ofToDataPath("assets") + "/" + settings["width"].asString() + "x" + settings["height"].asString() + "/";
    
    cout << "Assets folder: " << assets_path << endl;

    for(int i = 0; i < 10; i ++){
        string str = settings["background"][i].asString();
        int hex = std::strtol(str.c_str(), NULL, 16);
        back_colors[i] = hex;
    }
}

ofColor SettingsManager::get_current_color(){
    return ofColor::fromHex(back_colors[current_color]);
}

void  SettingsManager::randomize_color(){
    int prev_color = current_color;
    while(current_color == prev_color)
        current_color = int(ofRandom(10));
}