#ifndef PLAYER_H
#define PLAYER_H

#include <string>
class Move; 

class Player {
public:
    virtual ~Player() = default;
    virtual Move* makeMove() = 0;       // CHANGED: returns Move*
    virtual std::string getName() = 0;
};

#endif
