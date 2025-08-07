#include "Monkey.h"

bool Monkey::beats(Move* other) {
    std::string n = other->getName();
    return n == "Robot" || n == "Zombie";
}
