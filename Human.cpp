#include "Human.h"
#include <iostream>

Human::Human(){
    name = "human player";

}

char Human::makeMove(){
    char move;
    std::cout<<"Make your move (r,p,s) ";
    std::cin>>move;
    return move;
}

std::string Human::getName(){
    std::cout<<"What is your name: ";
    std::cin>>name;
    return name;

}