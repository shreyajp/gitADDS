#include "Computer.h"
#include "Human.h"
#include "Referee.h"
#include <iostream>

int main() {
    Human h("Shreya");
    Computer c;
    Referee r;

    Player* winner = r.refGame(&h, &c);
    if (!winner) std::cout << "It's a Tie\n";
    else         std::cout << winner->getName() << "\n";
    return 0;
}
