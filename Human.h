#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include <string>

class Human : public Player {
private:
    std::string name;
public:
    explicit Human(std::string name = "Human");
    ~Human() override = default;

    Move* makeMove() override;     
    std::string getName() override;
};

#endif
