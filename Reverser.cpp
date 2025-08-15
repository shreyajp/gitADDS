#include "Reverser.h"

int Reverser::reverseDigit(int value) {
    if (value < 0) {
        return -1;
    }
    return reverseDigitHelper(value, 0);
}

int Reverser::reverseDigitHelper(int value, int reversed) {
    if (value == 0) {
        return reversed;
    }
    int lastDigit = value % 10;
    return reverseDigitHelper(value / 10, reversed * 10 + lastDigit);
}

std::string Reverser::reverseString(const std::string& characters) {
    if (characters.empty()) {
        return "ERROR"; 
    }
    return reverseStringHelper(characters, characters.size() - 1);
}

std::string Reverser::reverseStringHelper(const std::string& str, int index) {
    if (index < 0) {
        return "";
    }
    return str[index] + reverseStringHelper(str, index - 1);
}

