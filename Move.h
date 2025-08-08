#ifndef MOVE_H
#define MOVE_H
#include <string>

class Move {
public:
    static Move* fromString(const std::string& rawName);   
    const std::string& getName() const { return name_; }
    int compare(const Move& other) const; 
private:
    explicit Move(const std::string& canonical) : name_(canonical) {}
    static std::string canonicalize(const std::string& s);
    static bool isValid(const std::string& s);
    static bool beats(const std::string& a, const std::string& b);
    std::string name_;
};
#endif
