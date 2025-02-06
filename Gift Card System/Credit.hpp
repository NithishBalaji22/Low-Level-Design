#pragma once
#include <iostream>
#include "Account.hpp"
#include "TransactionInterface.hpp"
using namespace std;

class Credit : public Transaction{
    public:
        Credit(Account* account, int amount) : Transaction(account, amount) {}
        void execute() override{
            account->credit(amount);
        }
};