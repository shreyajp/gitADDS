#ifndef REFEREE_H
#define REFEREE_H

#include "Computer.h"
#include "Human.h"

class Referee{
    public:
    Referee();
    Player* refGame(Player* p1, Player* p2);

};

#endif