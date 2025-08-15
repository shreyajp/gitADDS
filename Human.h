#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include <string>

class Human: public Player{
    private:
    std::string name;
    char move;

    public:
    Human();
    char makeMove() override;
    void setMove(char m);
    void setName(std::string n);
    std::string getName() override;

};

#endif