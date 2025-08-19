

int fib(int n){

    return fibHelp(n,1,0);

}

int fibHelp(int n, int acc, int prev){

    if (n==0){
        return prev;
    };

    if (n==1){
        return acc;
    };

    return fibHelp(n-1, acc+prev, acc);

}