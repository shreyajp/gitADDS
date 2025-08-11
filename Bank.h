#ifndef BANK_H
#define BANK_H
#include <string>

class BankAccount{
    private:
std::string name;
double balance;

    public:
BankAccount();
BankAccount(std::string n, double initialBalance);
double deposit(double amount);
double withdraw(double amount);
double getBalance();

}

#endif