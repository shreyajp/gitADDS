#include "Human.h"
#include "Move.h"
#include <iostream>
#include <utility>

Human::Human(std::string name) : name(std::move(name)) {}

Move* Human::makeMove() {
    std::string input;
    std::cin >> input;
    return createMove(input);   
}

std::string Human::getName() {
    return name;
}
