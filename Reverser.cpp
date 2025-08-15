#include "Reverser.h"

static int revDigits(int n, int acc) {
    if (n == 0) return acc;
    return revDigits(n / 10, acc * 10 + (n % 10));
}

int Reverser::reverseDigit(int value) {
    if (value < 0) return -1;    
    if (value == 0) return 0;   
    return revDigits(value, 0);
}

static std::string revStr(const std::string& s, std::size_t i) {
    if (i == s.size()) return std::string();
    std::string tail = revStr(s, i + 1);
    tail.push_back(s[i]);
    return tail;
}

std::string Reverser::reverseString(const std::string& characters) {
    if (characters.empty()) return "ERROR";  
    return revStr(characters, 0);
}
