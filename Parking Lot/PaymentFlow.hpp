#pragma once
#include <iostream>
#include "PaymentFlowInterface.hpp"
#include "Transaction.hpp"
#include "TransactionDebit.hpp"
#include "Account.hpp"
using namespace std;

class PaymentFlow : public PaymentFlowInterface{
    public:
        PaymentFlow(int id, Account* account, int amount) : PaymentFlowInterface(id, account, amount) {} 

        void validateUser(){
            int accPin;
            cout<<"Enter Account Pin: ";
            cin>>accPin;

            if(account->getPin() == accPin){
                cout<<"Welcome To Zoho Bank !!"<<endl;
            }else{
                cout<<"Wrong Pin exiting !!"<<endl;
                exit(0);
            }
        }

        void debitAmount(){
            cout<<"This could take couple of minutes !!"<<endl;
            this_thread::sleep_for(chrono::seconds(2));
            Transaction* debit = new Debit(id, account, amount);
            debit->execute();
        }
};