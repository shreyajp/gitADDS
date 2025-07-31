#include "Computer.h"
#include "Human.h"
#include "Referee.h"
#include <iostream>

int main(){
    Human h(shreya);
    Computer c;
    Referee r;

    Player* winner=r.refGame(&h, &c);

    if (winner == nullptr){
        std::cout<<"It's a Tie"<< std::endl;
    }
    else{
        std::cout <<winner->getName()<< "Wins"<< std::endl;
    }
return 0;
g++ main.cpp Human.cpp Computer.cpp Referee.cpp Player.cpp -o rps

}