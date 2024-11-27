#pragma once
#include <iostream>
#include "TransactionInterface.hpp"
#include "Account.hpp"
using namespace std;

class Debit : public TransactionInterface{
    public:
        Debit(int id, Account* account, int amount) : TransactionInterface(id, account, amount) {}
        void execute() override{
            account->debit(amount);
        }
};