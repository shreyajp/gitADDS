#include "Referee.h"
#include "Move.h"
#include <memory>

Referee::Referee() {}

Player* Referee::refGame(Player* player1, Player* player2) {
    std::unique_ptr<Move> m1(player1->makeMove());
    std::unique_ptr<Move> m2(player2->makeMove());

    if (!m1 || !m2) return nullptr; 

    if (m1->getName() == m2->getName()) return nullptr; 

    if (m1->beats(*m2)) return player1;
    if (m2->beats(*m1)) return player2;

    return nullptr;
}
