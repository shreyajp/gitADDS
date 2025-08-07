#include "Scissors.h"

bool Scissors::beats(Move* other) {
    std::string n = other->getName();
    return n == "Paper" || n == "Pirate";
}
