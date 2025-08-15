#include "Computer.h"
#include "Human.h"
#include "Referee.h"
#include <iostream>

int main(){
    Computer* c1 = new Computer();
    Human* h1 = new Human();
    std::string n;
    char m;

    std::cout<<"What is your name: "<<std::endl;
    std::cin>>n;
    h1->setName(n);
    std::cout<<"player is called "<<n<<std::endl;

    std::cout<<"Choose your move (r,p,s): "<<std::endl;
    std::cin>>m;
    h1->setMove(m);
    std::cout<<n<<" chose "<< m<<std::endl;

    Referee r1;
    r1.refGame(c1,h1);

    return 0;
}