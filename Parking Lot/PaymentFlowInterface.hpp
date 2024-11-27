#pragma once
#include <iostream>
#include "Transaction.hpp"
#include "TransactionDebit.hpp"
using namespace std;

class PaymentFlowInterface{
    protected:
        int id;
        Account* account;
        int amount;

    public:
        PaymentFlowInterface(int id, Account* account, int amount){
            this->id = id;
            this->account = account;
            this->amount = amount;
        }

        virtual void validateUser() = 0;
        virtual void debitAmount() = 0;

        void execute(){
            validateUser();
            debitAmount();
        }
};