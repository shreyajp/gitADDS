#include "Computer.h"
#include "Move.h"

Computer::Computer(std::string name) { this->name = std::move(name); }

Move* Computer::makeMove() {
    return createMove("Robot");
}

std::string Computer::getName() {
    return name;
}
