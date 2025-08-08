#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <initializer_list>
#include <vector>
#include <algorithm>

g++ -std=c++17 -Wall -Wextra -pedantic \
    main.cpp Player.cpp Human.cpp Computer.cpp Referee.cpp Move.cpp -o moropinzee
class Move {
public:
    virtual ~Move() = default;
    virtual std::string getName() const = 0;
    virtual bool beats(const Move& other) const = 0;
};

class SimpleMove : public Move {
public:
    SimpleMove(std::string name, std::initializer_list<std::string> beatsList)
        : name_(std::move(name)), beatsList_(beatsList) {}

    std::string getName() const override { return name_; }

    bool beats(const Move& other) const override {
        for (const auto& w : beatsList_) if (w == other.getName()) return true;
        return false;
    }

private:
    std::string name_;
    std::vector<std::string> beatsList_;
};

// RPS
class Rock     : public SimpleMove { public: Rock()     : SimpleMove("Rock",     {"Scissors"}) {} };
class Paper    : public SimpleMove { public: Paper()    : SimpleMove("Paper",    {"Rock"})     {} };
class Scissors : public SimpleMove { public: Scissors() : SimpleMove("Scissors", {"Paper"})    {} };

// MRPNZ
class Monkey : public SimpleMove { public: Monkey() : SimpleMove("Monkey", {"Ninja","Robot"}) {} };
class Robot  : public SimpleMove { public: Robot()  : SimpleMove("Robot",  {"Ninja","Zombie"}) {} };
class Pirate : public SimpleMove { public: Pirate() : SimpleMove("Pirate", {"Robot","Monkey"}) {} };
class Ninja  : public SimpleMove { public: Ninja()  : SimpleMove("Ninja",  {"Pirate","Zombie"}) {} };
class Zombie : public SimpleMove { public: Zombie() : SimpleMove("Zombie", {"Pirate","Monkey"}) {} };

#endif
