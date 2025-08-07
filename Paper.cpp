#include "Paper.h"

bool Paper::beats(Move* other) {
    std::string n = other->getName();
    return n == "Rock" || n == "Robot";
}
