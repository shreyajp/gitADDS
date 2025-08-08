#include "Human.h"
#include "Move.h"
#include <iostream>
#include <algorithm>

static std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

Human::Human(std::string name) : name(std::move(name)) {}

Move* Human::makeMove() {
    std::string s;
    std::cout << "Enter Move (Rock, Paper, Scissors, Robot, Monkey, Pirate, Ninja, Zombie): ";
    std::cin >> s;
    s = toLower(s);

    // Build the chosen move directly (no factory file)
    if (s == "rock")     return new Rock();
    if (s == "paper")    return new Paper();
    if (s == "scissors") return new Scissors();
    if (s == "monkey")   return new Monkey();
    if (s == "robot")    return new Robot();
    if (s == "pirate")   return new Pirate();
    if (s == "ninja")    return new Ninja();
    if (s == "zombie")   return new Zombie();

    // Undefined behavior per brief; return nullptr -> treat as tie
    return nullptr;
}

std::string Human::getName() {
    return name;
}
