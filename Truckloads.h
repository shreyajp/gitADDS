#ifndef REVERSER_H
#define REVERSER_H
#include <string>

class Reverser{
    private:
    std::string characters;
    int value;

    public:
    int reverseDigit(int value);
    int reverseDigitH(int value, int acc);
    std::string reverseString(std::string characters);
    std::string reverseStringH(std::string characters, std::string reverseChar);

};

#endif