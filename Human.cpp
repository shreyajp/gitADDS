#include "Human.h"
#include <iostream>

Human::Human(){
    name = "human player";
}

void Human::setName(std::string n){
     this->name=n; 
}

void Human::setMove(char m){
    this->move=m;
}

char Human::makeMove(){
    return move;
}


std::string Human::getName(){
    return name;

}