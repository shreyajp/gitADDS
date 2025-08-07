#include "Zombie.h"

bool Zombie::beats(Move* other) {
    std::string n = other->getName();
    return n == "Paper" || n == "Ninja";
}
