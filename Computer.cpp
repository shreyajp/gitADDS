#include "Computer.h"
#include "Move.h"
#include <random>
#include <array>

Computer::Computer(std::string name) : name(std::move(name)) {}

Move* Computer::makeMove() {
    static std::mt19937 rng{ std::random_device{}() };
    static const std::array<int,8> ids = {0,1,2,3,4,5,6,7};
    std::uniform_int_distribution<int> dist(0, (int)ids.size()-1);

    switch (ids[dist(rng)]) {
        case 0: return new Rock();
        case 1: return new Paper();
        case 2: return new Scissors();
        case 3: return new Monkey();
        case 4: return new Robot();
        case 5: return new Pirate();
        case 6: return new Ninja();
        case 7: return new Zombie();
        default: return new Rock();
    }
}

std::string Computer::getName() { return name; }
