#pragma once
#include <iostream>
using namespace std;

class Account;
class Transaction{
    protected:
        int transactionId;
        Account* account;   
        int amount;

    public:
        Transaction(int id, Account* account, int amount){
            transactionId = id;
            this->account = account;
            this->amount = amount;
        }     

        //Strategy Design Pattern
        virtual void execute() = 0;
};