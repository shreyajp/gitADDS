#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include <string>

class Human : public Player {
public:
    explicit Human(std::string name = "Human") : name(name) {}
    Move* makeMove() override;
    std::string getName() override { return name; }
private:
    std::string name;
};
#endif
