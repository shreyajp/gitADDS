#include "Computer.h"
#include <cstdlib>
#include <ctime>
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Monkey.h"
#include "Robot.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"

Computer::Computer(std::string name) {
    this->name = name;
    std::srand(std::time(nullptr));
}

Move* Computer::makeMove() {
    int choice = rand() % 8;
    switch (choice) {
        case 0: return new Rock();
        case 1: return new Paper();
        case 2: return new Scissors();
        case 3: return new Monkey();
        case 4: return new Robot();
        case 5: return new Pirate();
        case 6: return new Ninja();
        case 7: return new Zombie();
    }
    return new Rock();
}

std::string Computer::getName() {
    return name;
}
