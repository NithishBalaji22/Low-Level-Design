#pragma once
#include <iostream>
using namespace std;

class Account;
class MiniStatement;
class PaymentFlow{
    protected:
        int id;
        Account* sender;
        Account* receiver;
        int amount;

    public:
        PaymentFlow(int id, Account* sender, Account* receiver, int amount){
            this->id = id;
            this->sender = sender;
            this->receiver = receiver;
            this->amount = amount;
        }

        virtual void validateSender() = 0;
        virtual void debit() = 0;
        virtual void credit() = 0;

        void execute(){
            // Step 1
            validateSender();

            // Step 2
            debit();

            //Step 3
            credit();
        }
};