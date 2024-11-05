#pragma once
#include <iostream>
using namespace std;

class Account{
    private:
        int accNo;
        int pin;
        int balance;

    public:
        Account(int accNo, int pin, int balance){
            this->accNo = accNo;
            this->pin = pin;
            this->balance = balance;
        }

        int getAccountNo(){
            return accNo;
        }

        int getPin(){
            return pin;
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