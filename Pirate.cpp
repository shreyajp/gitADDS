#include "Pirate.h"

bool Pirate::beats(Move* other) {
    std::string n = other->getName();
    return n == "Monkey" || n == "Robot";
}
