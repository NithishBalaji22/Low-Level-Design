#pragma once
#include <iostream>
#include "TransactionInterface.hpp"
#include "Account.hpp"
using namespace std;

class DebitTransaction : public Transaction{
    public:
        DebitTransaction (int trasactionId, Account* account, int amount) : Transaction(trasactionId, account, amount) {}
        void execute() override{
            account->debit(amount);
        }
};