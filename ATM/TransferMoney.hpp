#pragma once
#include <iostream>
#include <thread>
#include "PaymentFlow.hpp"
using namespace std;

class Account;
class TransferMoney : public PaymentFlow{
    public:
        TransferMoney(int id, Account* sender, Account* receiver, int amount) : PaymentFlow (id, sender, receiver, amount) {}

        void validateSender();
        void debit();
        void credit();
};