#include <iostream>

int recurseH(int n, int acc){
    if (n==0){
        return acc;
    }

    return recurseH(n-1, acc+(n*(n-1)));

}

int recurse(int n){

    return recurseH(n, 0);

}

int main(){

    std::cout<<recurse(2)<<std::endl;

} 