#ifndef NINJA_H
#define NINJA_H
#include "Move.h"

class Ninja : public Move {
public:
    std::string getName() const override { return "Ninja"; }
    bool beats(Move* other) override;
};

#endif
