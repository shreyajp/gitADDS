#include "Referee.h"
#include <iostream>

Referee::Referee(){
}

Player* Referee::refGame(Player* p1, Player* p2){

std::string name1 = p1->getName();
std::cout<<name1<<std::endl;

std::string name2 = p2->getName();
std::cout<<name2<<std::endl;

char move1 = p1->makeMove();
std::cout<<"player 1 plays: "<<move1<<std::endl;
char move2 = p2->makeMove();
std::cout<<"player 2 plays: "<<move2<<std::endl;

if (move1==move2){
    std::cout<<"its a tie"<<std::endl;
}
else if((move1=='r' && move2=='s')||(move1=='p' && move2=='r')||(move1=='s' && move2=='p')){
    std::cout<<"winner: "<< name1<< std::endl;
    return p1;
    
}
else {
    std::cout<<"Winner: "<< name2<< std::endl;
    return p2;
};

}
