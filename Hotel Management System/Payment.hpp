#pragma once
#include <iostream>
#include "Account.hpp"
using namespace std;

class Account;
class Payment{
    protected:
        int paymentId;
        Account* account;
        int amount;

    public:
        Payment(int id, Account* account, int amount){
            paymentId = id;
            this->account = account;
            this->amount = amount;
        }

        int getPaymentId(){
            return paymentId;
        }

        int getAmount(){
            return amount;
        }

        virtual void execute() = 0;

};