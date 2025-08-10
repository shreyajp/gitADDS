#include "Computer.h"
#include "Move.h"
#include <utility>

Computer::Computer(std::string name) : name(std::move(name)) {}

Move* Computer::makeMove() {
    return createMove("Rock");
}

std::string Computer::getName() {
    return name;
}
