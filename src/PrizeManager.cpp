//
//  PrizeManager.cpp
//  pull_carrousel
//
//  Created by miguel valero espada on 8/9/14.
//
//

#include "PrizeManager.h"


string PrizeManager::present_time(){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    
    strftime(buffer,80,"%H:%M:%S",timeinfo);
    std::string str(buffer);
    return str;
};

int PrizeManager::next_prize(){
    
    prizes.open(ofToDataPath("premios.json"));
    int i = 0;
    while(i < prizes.size()){
        if(prizes[i]["enabled"].asInt() == 1)
            return i;
        i ++;
    }
    return -1;
};

bool PrizeManager::is_prize_enabled(){
    
    currentPrizeIndex = next_prize();
    if(currentPrizeIndex == -1) return false;
    
    string now = present_time();
    return prizes[currentPrizeIndex]["date"].asString() <= now;
}

void PrizeManager::disable_current_prize(){
    if(currentPrizeIndex != -1){
        cout << get_current_prize() << " disabled" << endl;
        prizes[currentPrizeIndex]["enabled"] = 0;
        prizes.save(ofToDataPath("premios.json"), true);
        currentPrizeIndex = -1;
    }
};

string PrizeManager::get_current_prize(){
    return prizes[currentPrizeIndex]["prize"].asString();
}

int PrizeManager::seconds_to_next_prize(){
    int i = next_prize();
    if(i == -1) return -1;
    string now = present_time();
    string next_prize = prizes[i]["date"].asString();
    
    int h,m,s,hh,mm,ss;
    sscanf (now.c_str(),"%d:%d:%d",&h,&m,&s);
    sscanf (next_prize.c_str(),"%d:%d:%d",&hh,&mm,&ss);
    return ((hh - h) * 60 + (mm - m)) * 60 + ss - s;
    
}
