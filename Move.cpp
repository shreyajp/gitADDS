#include "Move.h"
#include <cctype>

static const char* VALID[] = {
    "Rock","Paper","Scissors","Robot","Monkey","Pirate","Ninja","Zombie"
};
static const int VALID_N = 8;

static const char* WINS[][2] = {
    {"Rock","Scissors"},
    {"Paper","Rock"},
    {"Scissors","Paper"},
    {"Monkey","Robot"},
    {"Robot","Ninja"},
    {"Ninja","Pirate"},
    {"Pirate","Zombie"},
    {"Zombie","Monkey"}
};
static const int WINS_N = 8;

std::string Move::canonicalize(const std::string& s){
    std::string out; out.reserve(s.size());
    bool first = true;
    for(char c: s){
        if(first){ out.push_back(std::toupper((unsigned char)c)); first=false; }
        else{ out.push_back(std::tolower((unsigned char)c)); }
    }
    return out;
}

bool Move::isValid(const std::string& s){
    for(int i=0;i<VALID_N;i++) if (s == VALID[i]) return true;
    return false;
}

bool Move::beats(const std::string& a, const std::string& b){
    for(int i=0;i<WINS_N;i++) if(a==WINS[i][0] && b==WINS[i][1]) return true;
    return false;
}

Move* Move::fromString(const std::string& rawName){
    std::string c = canonicalize(rawName);
    if(!isValid(c)) return nullptr;
    return new Move(c);
}

int Move::compare(const Move& other) const{
    if(name_ == other.name_) return 0;
    if(beats(name_, other.name_)) return +1;
    if(beats(other.name_, name_)) return -1;
    return 0;
}
