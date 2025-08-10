#include "Move.h"
#include <algorithm>
#include <cctype>


namespace {
    std::string toLower(std::string s) {
        for (char& c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        return s;
    }

    class NamedMove : public Move {
    protected:
        std::string name_;
    public:
        explicit NamedMove(std::string n) : name_(std::move(n)) {}
        std::string getName() const override { return name_; }
    };

    class Rock    : public NamedMove { public: Rock()    : NamedMove("Rock")    {} bool defeats(const Move& o) const override; };
    class Paper   : public NamedMove { public: Paper()   : NamedMove("Paper")   {} bool defeats(const Move& o) const override; };
    class Scissor : public NamedMove { public: Scissor() : NamedMove("Scissors"){} bool defeats(const Move& o) const override; };
    class Monkey  : public NamedMove { public: Monkey()  : NamedMove("Monkey")  {} bool defeats(const Move& o) const override; };
    class Robot   : public NamedMove { public: Robot()   : NamedMove("Robot")   {} bool defeats(const Move& o) const override; };
    class Pirate  : public NamedMove { public: Pirate()  : NamedMove("Pirate")  {} bool defeats(const Move& o) const override; };
    class Ninja   : public NamedMove { public: Ninja()   : NamedMove("Ninja")   {} bool defeats(const Move& o) const override; };
    class Zombie  : public NamedMove { public: Zombie()  : NamedMove("Zombie")  {} bool defeats(const Move& o) const override; }

    ;


    inline bool isRock   (const Move& m){ return m.getName()=="Rock"; }
    inline bool isPaper  (const Move& m){ return m.getName()=="Paper"; }
    inline bool isScissor(const Move& m){ return m.getName()=="Scissors"; }
    inline bool isMonkey (const Move& m){ return m.getName()=="Monkey"; }
    inline bool isRobot  (const Move& m){ return m.getName()=="Robot"; }
    inline bool isPirate (const Move& m){ return m.getName()=="Pirate"; }
    inline bool isNinja  (const Move& m){ return m.getName()=="Ninja"; }
    inline bool isZombie (const Move& m){ return m.getName()=="Zombie"; }
} 

bool Rock::defeats(const Move& o) const {
    return isScissor(o) || isZombie(o);
}

bool Paper::defeats(const Move& o) const {

    return isRock(o) || isRobot(o);
}

bool Scissor::defeats(const Move& o) const {

    return isPaper(o) || isMonkey(o);
}

bool Monkey::defeats(const Move& o) const {
    return isRobot(o) || isNinja(o);
}

bool Robot::defeats(const Move& o) const {
    return isPirate(o) || isZombie(o);
}

bool Pirate::defeats(const Move& o) const {
    return isNinja(o) || isMonkey(o);
}

bool Ninja::defeats(const Move& o) const {
    return isZombie(o) || isPirate(o);
}

bool Zombie::defeats(const Move& o) const {
    return isMonkey(o) || isPaper(o);
}

Move* createMove(const std::string& text) {
    const std::string k = toLower(text);
    if (k == "rock")     return new Rock();
    if (k == "paper")    return new Paper();
    if (k == "scissor" || k == "scissors") return new Scissor();
    if (k == "robot")    return new Robot();
    if (k == "monkey")   return new Monkey();
    if (k == "pirate")   return new Pirate();
    if (k == "ninja")    return new Ninja();
    if (k == "zombie")   return new Zombie();
    return nullptr;
}
