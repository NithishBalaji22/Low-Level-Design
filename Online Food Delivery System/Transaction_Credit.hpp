#pragma once
#include <iostream>
#include "Transaction_Interface.hpp"
using namespace std;

class Credit : public Transaction{
    public:
        Credit(int id, Account* account, int amount) : Transaction(id, account, amount) {}
        void execute() override{
            account->credit(amount);
        }
};