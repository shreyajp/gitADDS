#include "Robot.h"

bool Robot::beats(Move* other) {
    std::string n = other->getName();
    return n == "Ninja" || n == "Zombie";
}
