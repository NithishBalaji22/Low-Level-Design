#pragma once
#include <iostream>
using namespace std;

class Account;
class Transaction{
    protected:
        Account* account;
        int amount;

    public:
        Transaction(Account* account, int amount){
            this->account = account;
            this->amount = amount;
        }

        virtual void execute() = 0;
};