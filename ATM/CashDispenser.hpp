#pragma once
#include<iostream>
#include "Account.hpp"
using namespace std;

class CashDispenser{
    private:
        int cashAvailable;
    
    public:
        CashDispenser(int initialCash){
            cashAvailable = initialCash;
        }

        void disPenseCash(int amount){
            if(amount <= cashAvailable){
                cashAvailable -= amount;
                cout<<"Cash Dispence: "<<amount<<'\n';
                return;
            }

            cout<<"Insufficient Cash is available in the ATM Sorry for the inconvinience";
            return;
        }    
};
