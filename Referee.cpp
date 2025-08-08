#include "Referee.h"
#include "Move.h"

Player* Referee::refGame(Player* player1, Player* player2){
    if(!player1 || !player2) return nullptr;

    Move* m1 = player1->makeMove();
    Move* m2 = player2->makeMove();

    if(!m1 || !m2){ delete m1; delete m2; return nullptr; }

    int r = m1->compare(*m2);
    delete m1; delete m2;

    if(r > 0)  return player1;
    if(r < 0)  return player2;
    return nullptr; 
}
