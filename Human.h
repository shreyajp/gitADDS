#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include <string>

class Human{
    private:
    std::string name;

    public:
    Human();
    char makeMove() override;
    std::string getName() override;

};

#endif