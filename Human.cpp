#include <iostream>
#include "Human.h" 

Human:: Human(std::string name){
    this->name = name;
}

char Human::makeMove(){
char move;
std::cout<< "enter move: ";
std::cin >> move;
return move;
}

std::string Human::getName(){
    return name;
}
