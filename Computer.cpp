#include "Computer.h"
#include <string>

Computer::Computer(){
    name = "Computer";
}

char Computer::makeMove(){
    char move = 'r';
    return move;
}

std::string Computer::getName(){
    return name;
}