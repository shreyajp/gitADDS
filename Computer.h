#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

class Computer(){
public: 

Computer(std::string name = "Computer");
char makeMove() override;
std::string getName() override;

};

#endif