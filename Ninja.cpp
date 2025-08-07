#include "Ninja.h"

bool Ninja::beats(Move* other) {
    std::string n = other->getName();
    return n == "Pirate" || n == "Monkey";
}
