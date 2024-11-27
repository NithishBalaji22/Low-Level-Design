#pragma once
#include <iostream>
using namespace std;

class Account{
    private:
        int accNo;
        string accountHolder;
        int pin;    
        int balance;

    public:
        Account(int accNo, string accountHolder, int pin, int balance){
            this->accNo = accNo;
            this->accountHolder = accountHolder;
            this->pin = pin;
            this->balance = balance;
        }

        int getAccountNo(){
            return accNo;
        }

        int getPin(){
            return pin;
        }

        string getName(){
            return accountHolder;
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