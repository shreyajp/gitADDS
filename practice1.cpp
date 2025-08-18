#include "practice1.h"
#include <algorithm>

std::vector<std::string> PotionCraft::getPotions(){

    return inventory;

}

void PotionCraft::brewPotion(std::string name){
    inventory.push_back(name);
    return;

}

std::string PotionCraft::consumePotion(std::string name){

    auto it=std::find(inventory.begin(),inventory.end(),name);
    if (it!=inventory.end()){
        inventory.erase(it);
    };
    return name;

}

void PotionCraft::brewMultiplePotions(std::vector<std::string> potions){
    for (auto it=potions.begin(); it!=potions.end();++it){
        inventory.push_back(*it);

    };
    return;

}

std::vector<std::string> PotionCraft::fillExternalContainer(std::vector<std::string>& container){

    for (auto it=inventory.begin(); it!= inventory.end(); ++it){
        container.push_back(*it);
    };
    return container;

}