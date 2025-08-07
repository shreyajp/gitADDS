#include "Rock.h"
#include <string>

bool Rock::beats(Move* other) {
    std::string otherName = other->getName();
    return otherName == "Scissors" || otherName == "Monkey";
}
