#include "Computer.h"
#include "Human.h"
#include "Referee.h"

int main(){
    Computer c1;
    Human h1;

    Referee r1;
    r1.refGame(c1,h1);
    return 0;
}