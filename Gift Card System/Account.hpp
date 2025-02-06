#pragma once
#include <iostream>
using namespace std;

class Account{
    private:
        int customerID;
        int balance;

    public:
        Account(int customerID, int balance){
            this->customerID = customerID;
            this->balance = balance;
        }

        int getCustomerID(){
            return customerID;
        }

        int getBalance(){
            return balance;
        }

        void debit(int amount){
            balance -= amount;
        }

        void credit(int amount){
            balance += amount;
        }
};