#pragma once
#include <iostream>
#include "Account.hpp"
using namespace std;

class Transaction{
    protected:
        int transactionId;
        Account* account;
        int amount;

    public:
        Transaction(int id, Account* ac, int amt){
            transactionId = id;
            account = ac;
            amount = amt;
        }

        virtual void execute() = 0;
};