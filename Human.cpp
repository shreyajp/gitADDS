#include "Human.h"
#include <iostream>
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Monkey.h"
#include "Robot.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"

Human::Human(std::string name) {
    this->name = name;
}

Move* Human::makeMove() {
    std::string moveInput;
    std::cout << "Enter move: ";
    std::cin >> moveInput;

    for (auto& c : moveInput) c = std::toupper(c);

    if (moveInput == "ROCK") return new Rock();
    if (moveInput == "PAPER") return new Paper();
    if (moveInput == "SCISSORS") return new Scissors();
    if (moveInput == "MONKEY") return new Monkey();
    if (moveInput == "ROBOT") return new Robot();
    if (moveInput == "PIRATE") return new Pirate();
    if (moveInput == "NINJA") return new Ninja();
    if (moveInput == "ZOMBIE") return new Zombie();

    std::cout << "Invalid move. Defaulting to Rock.\n";
    return new Rock();
}

std::string Human::getName() {
    return name;
}
