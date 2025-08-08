#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
#include <string>

class Computer : public Player {
public:
    explicit Computer(std::string name = "Computer") : name(name) {}
    Move* makeMove() override;
    std::string getName() override { return name; }   
private:
    std::string name;
    int index = 3;  
};
#endif
