#include "Bank.h"
#include <string>
#include <iostream>

BankAccount::BankAccount(){
    name = "Unnamed";
    balance = 0.0;
}

BankAccount::BankAccount(std::string n, double initialBalance){
    name=n;
    balance=initialBalance;
}

double BankAccount::deposit(double amount){
    balance = balance+amount;
    return balance;
}

double BankAccount::withdraw(double amount){
    if (amount<0){
        std::cout<<"Not valid"<<std::endl;
    }
    if (balance>amount){
    balance= balance-amount;
    return balance;
    }
    else{
        std::cout<<"not enough funds"<<std::endl;
    }
}

double BankAccount::getBalance(){

    std::cout<<"your balance is: "<<balance<<std::endl;
}

