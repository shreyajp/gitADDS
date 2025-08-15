#ifndef REVERSER_H
#define REVERSER_H

#include <string>

class Reverser {
public:
    int reverseDigit(int value);
    std::string reverseString(const std::string& characters);

private:
    int reverseDigitHelper(int value, int reversed);
    std::string reverseStringHelper(const std::string& str, int index);
};

#endif
