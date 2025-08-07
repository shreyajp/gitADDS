#include "Referee.h"
#include <iostream>

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    std::cout << player1->getName() << " chose " << move1->getName() << std::endl;
    std::cout << player2->getName() << " chose " << move2->getName() << std::endl;

    if (move1->getName() == move2->getName())
        return nullptr;

    return move1->beats(move2) ? player1 : player2;
}
