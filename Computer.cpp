#include "Computer.h"
#include "Move.h"

Move* Computer::makeMove(){
    static const char* cycle[] = {
        "Rock","Paper","Scissors","Robot","Monkey","Pirate","Ninja","Zombie"
    };
    const int n = 8;
    const char* pick = cycle[index % n];
    index++;
    return Move::fromString(pick);
}
