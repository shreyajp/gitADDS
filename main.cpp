#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include <iostream>

int main() {
    Human h("Shreya");
    Computer c;
    Referee r;

    Player* winner = r.refGame(&h, &c);

    if (winner == nullptr)
        std::cout << "It's a Tie" << std::endl;
    else
        std::cout << winner->getName() << " Wins" << std::endl;

    return 0;
}
