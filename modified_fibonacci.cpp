#include <vector>

std::vector<int> modifiedFibonacci(int n){
   
   std::vector<int> acc;
    if (n<=0){
        return acc;
    };
    
    acc.push_back(2);

    mf_Helper(n, 1, 2, 3, acc);

}



void mf_Helper(int n, int i, int prev, int curr, std::vector<int>& acc){
    if (i>=n){
        return;
    };
    acc.push_back(curr);

    mf_Helper(n, i+1, prev, curr*prev, acc);

}