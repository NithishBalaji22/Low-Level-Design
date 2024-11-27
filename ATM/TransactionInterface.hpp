#pragma once
#include <iostream>
using namespace std;

class Account;
class TransactionInterface{
    protected:
        int id;
        Account* account;
        int amount;

    public:
        TransactionInterface(int id, Account* account, int amount){
            this->id = id;
            this->account = account;
            this->amount = amount;
        }

        virtual void execute() = 0;
};