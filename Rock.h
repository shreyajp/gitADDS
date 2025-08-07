#ifndef ROCK_H
#define ROCK_H
#include "Move.h"

class Rock : public Move {
public:
    std::string getName() const override { return "Rock"; }
    bool beats(Move* other) override;
};

#endif
