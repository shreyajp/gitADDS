#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include <string>

Class Human: Public Player {

    private: 
    std::string name;

    public:
    Human(std::string name = "Human")

    char makeMove() override ;
    std::string getName() override ;


};

#endif