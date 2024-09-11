#pragma once
#include<iostream>
#include<unordered_map>
#include "Transaction.hpp"
#include "Account.hpp"
using namespace std;

class BankingSystem{
    private:
        unordered_map<string, Account*> accounts;

    public:
        void CreateAccount(string accountNumber, int balance){
            accounts.insert({accountNumber, new Account(accountNumber, balance)});
        }

        Account* getAccount(string accountNumber){
            if(accounts.find(accountNumber) != accounts.end()){
                return accounts[accountNumber];
            }

            cout<<"The account you are looking for is not in our database"<<'\n';
            return nullptr;
        }

        bool processTransaction(Transaction* transaction){
            transaction->execute();
        }
};