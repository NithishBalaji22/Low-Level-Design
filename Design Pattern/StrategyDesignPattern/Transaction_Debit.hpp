#pragma once
#include "Transaction.hpp"
#include "Account.hpp"
using namespace std;

class Debit : public Transaction{
    public:
        Debit(int id, Account* account, int amount) : Transaction(id, account, amount) {}
        void execute() override{
            account->debit(amount);
        }
};