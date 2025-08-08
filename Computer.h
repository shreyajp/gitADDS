#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <string>

class Computer : public Player {
private:
    std::string name;
public:
    explicit Computer(std::string name = "Computer");
    Move* makeMove() override;        
    std::string getName() override;
};

#endif
