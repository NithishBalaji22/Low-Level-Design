#pragma once
#include <iostream>
#include "Account.hpp"
using namespace std;

class Card{
    private:
        int cardNum;
        int pin;
        Account* account;

    public:
        Card(int cardNum, int pin, Account* account){
            this->cardNum = cardNum;
            this->pin = pin;
            this->account = account;
        }

        Account* getAccount(){
            return account;
        }

        int getPin(){
            return pin;
        }

        void setPin(int pin){
            this->pin = pin;
        }
};