#include"Account.hpp"
#include"ATM.hpp"
#include"BankingSystem.hpp"
#include"Card.hpp"
#include"CashDispenser.hpp"
#include"Transaction.hpp"

#include<bits/stdc++.h>
using namespace std;

int main(){
    BankingSystem* bankingSystem = new BankingSystem();
    CashDispenser* dispencer = new CashDispenser(10000);
    ATM* atm = new ATM(bankingSystem, dispencer);

    bankingSystem->CreateAccount("12345", 5000);
    bankingSystem->CreateAccount("678910", 5000);

    Card* card = new Card("123", "2812");
    atm->authenticateCard(card);

    double balance = atm->checkBalance("12345");
    cout<<"Current Balance: "<<balance<<'\n';

    atm->withdrawalCash("12345", 500);
    balance = atm->checkBalance("12345");
    cout<<"Current Balance: "<<balance<<'\n';
}