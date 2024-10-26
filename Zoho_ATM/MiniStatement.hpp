#pragma once
#include<iostream>
using namespace std;

class MiniStatement{
    private:
        int transactionId;
        string transactionRemarks;
        string transactionType;
        int transactionAmount;

    public:
        MiniStatement(int transactionId, string transactionRemarks, string transactionType, int transactionAmount){
            this->transactionId = transactionId;
            this->transactionRemarks = transactionRemarks;
            this->transactionType = transactionType;
            this->transactionAmount = transactionAmount;
        }

        int getTransactionId(){
            return transactionId;
        }

        string getTransactionRemarks(){
            return transactionRemarks;
        }

        string getTransactionType(){
            return transactionType;
            
        }

        int getTransactionAmount(){
            return transactionAmount;           
        }
};