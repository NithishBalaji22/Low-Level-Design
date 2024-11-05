#pragma once
#include <iostream>
using namespace std;

class Account{
    private:
        int id;
        int accNo;
        int pin;
        int balance;

    public:
        Account(int id, int accNo, int pin, int balance){
            this->id = id;
            this->accNo = accNo;
            this->pin = pin;
            this->balance = balance;
        }

        int getId(){
            return id;
        }

        int getAccNo(){
            return accNo;
        }

        int getPin(){
            return pin;
        }

        int getBalance(){
            return balance;
        }

        void credit(int amount){
            balance += amount;
        }

        void debit(int amount){
            balance -= amount;
        }
};