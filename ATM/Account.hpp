#pragma once
#include<iostream>
using namespace std;

class Account{
    private:
        string accountNumber;
        double balance;

    public:
        Account(string accountNumber, double balance){
            this->accountNumber = accountNumber;
            this->balance = balance;
        }

        double getBalance(){
            return balance;
        }

        bool debit(double amount){
            if(amount <= balance){
                balance -= amount;
                return true;
            }
            
            cout<<"Insufficient Fund"<<'\n';
            return false;            
        }

        bool credit(double amount){
            balance += amount;
            return true;
        }
};