#pragma once
#include <iostream>
using namespace std;

class Account{
    private:
        int accountNum;
        string acHolderName;
        int balance;
        
    public:
        Account(int accountNum, string acHolderName, int balance){
            this->accountNum = accountNum;
            this->acHolderName = acHolderName;
            this->balance = balance;
        }

        int checkBalance(){
            return balance;
        }
        
        void debit(int amount){
            balance -= amount;
        }

        void credit(int amount){
            balance += amount;
        }

        int getAccountNum(){
            return accountNum;
        }

        string getAcHolderName(){
            return acHolderName;
        }

        int getBalance(){
            return balance;
        }

        void setBalance(int amount){
            balance = amount;
        }
};