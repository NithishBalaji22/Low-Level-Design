#pragma once
#include <iostream>
#include "Account.hpp"
#include "TransactionInterface.hpp"
using namespace std;

class Debit : public Transaction{
    public:
        Debit(Account* account, int amount) : Transaction(account, amount) {}
        void execute() override{
            account->debit(amount);
        }
};