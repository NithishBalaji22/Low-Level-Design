#pragma once
#include <iostream>
#include "TransactionInterface.hpp"
#include "Account.hpp"
using namespace std;

class CreditTransaction : public Transaction{
    public:
        CreditTransaction(int transactionId, Account* account, int amount) : Transaction(transactionId, account, amount) {}
        void execute() override{
            account->credit(amount);
        }
};