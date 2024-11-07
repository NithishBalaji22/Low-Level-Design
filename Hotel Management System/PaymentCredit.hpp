#pragma once
#include <iostream>
#include "Payment.hpp"
#include "Account.hpp"
using namespace std;

class Credit : public Payment{
    public:
        Credit(int id, Account* account, int amount) : Payment(id, account, amount) {}
        void execute() override{
            account->credit(amount);
        }
};