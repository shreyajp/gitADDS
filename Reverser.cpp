#include "Reverser.h"
#include <string>

int Reverser::reverseDigit(int value) {
    if (value < 0) return -1; 
    if (value < 10) return value; 

    int lastDigit = value % 10;
    int remaining = value / 10;

    int multiplier = 1;
    int temp = remaining;
    while (temp > 0) {
        multiplier *= 10;
        temp /= 10;
    }

    return lastDigit * multiplier + reverseDigit(remaining);
}

std::string Reverser::reverseString(const std::string &characters) {
    if (characters.empty()) return "ERROR"; 
    if (characters.size() == 1) return characters; 

    return characters.back() + reverseString(characters.substr(0, characters.size() - 1));
}
