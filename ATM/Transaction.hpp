#pragma once
#include<iostream>
#include "Account.hpp"
using namespace std;

//Strategy Design pattern
class Transaction{
    protected:
        string transactionId;
        Account* account;
        double amount;

    public:
        Transaction(string transactionId, Account* account, double amount){
            this->transactionId = transactionId;
            this->account = account;
            this->amount = amount;
        }
        virtual bool execute() = 0;
};

class DepositTransaction : public Transaction{
    public:
        DepositTransaction(string transactionId, Account* account, double amount) : Transaction(transactionId, account, amount) {}

        bool execute() override{
            account->credit(amount);
        }
};


class WithdrawalTransaction : public Transaction{
    public:
        WithdrawalTransaction(string transactionId, Account* account, double amount) : Transaction(transactionId, account, amount) {}

        bool execute() override{
            account->debit(amount);
        }
};
