#include "Referee.h"
#include "Move.h"

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
    Move* m1 = player1->makeMove();
    Move* m2 = player2->makeMove();

    if (!m1 || !m2) { delete m1; delete m2; return nullptr; }

    Player* winner = nullptr;
    if (m1->defeats(*m2))      winner = player1;
    else if (m2->defeats(*m1)) winner = player2;
    else                       winner = nullptr;

    delete m1; delete m2;
    return winner;
}
