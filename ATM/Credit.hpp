#pragma once
#include <iostream>
#include "TransactionInterface.hpp"
#include "Account.hpp"
using namespace std;

class Credit : public TransactionInterface{
    public:
        Credit(int id, Account* account, int amount) : TransactionInterface(id, account, amount) {}
        void execute() override{
            account->credit(amount);
        }
};