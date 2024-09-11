#pragma once
#include"BankingSystem.hpp"
#include"CashDispenser.hpp"
#include"Card.hpp"
#include<iostream>
using namespace std;

class ATM{
    private:
        BankingSystem* bankingSystem;
        CashDispenser* dispenser;
    
    public:
        ATM(BankingSystem* bankingSystem, CashDispenser* dispenser){
            this->bankingSystem = bankingSystem;
            this->dispenser = dispenser;
        }

        bool authenticateCard(Card* card);
        double checkBalance(string accountNumber);
        bool withdrawalCash(string accountNumber, double amount);
        bool depositCash(string accountNumber, double amount);
        string generateTransactionId();
};