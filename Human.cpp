#include "Human.h"
#include "Move.h"
#include <iostream>

Move* Human::makeMove(){
    std::string typed;
    std::cout << "Enter Move: ";
    std::getline(std::cin, typed);
    if(typed.empty()) std::getline(std::cin, typed); 
    return Move::fromString(typed); 
}
