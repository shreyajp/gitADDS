#include <iostream>
#include "Human.h"
#include "Move.h"

Human::Human(std::string name) { this->name = std::move(name); }

Move* Human::makeMove() {
    std::cout << "Enter move (Rock, Paper, Scissors, Robot, Monkey, Pirate, Ninja, Zombie): ";
    std::string input;
    std::cin >> input;
    return createMove(input);
}

std::string Human::getName() {
    return name;
}
