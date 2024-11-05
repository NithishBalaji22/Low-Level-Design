#pragma once
#include <iostream>
#include "Payment.hpp"
#include "Account.hpp"
using namespace std;

class Debit : public Payment{
    public:
        Debit(int id, Account* account, int amount) : Payment(id, account, amount) {}
        void execute() override{
            account->debit(amount);
        }
};