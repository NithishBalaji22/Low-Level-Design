#pragma once
#include<iostream>
using namespace std;

class Card{
    private:
        string cardNumber;
        string pin;

    public:
        Card(string cardNumber, string pin){
            this->cardNumber = cardNumber;
            this->pin = pin;
        }

        string getPin(){
            return pin;
        }
        
};