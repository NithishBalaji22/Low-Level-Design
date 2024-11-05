#pragma once
#include <iostream>
using namespace std;

class Account;
class Payment{
    protected:
        int paymentId;
        Account* account;
        int amount;

    public:
        Payment(int id, Account* account, int amount){
            this->paymentId = id;
            this->account = account;
            this->amount = amount;
        }

        virtual void execute() = 0;
};