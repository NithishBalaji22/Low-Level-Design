#pragma once
#include <iostream>
using namespace std;

class PurchaseTransactionSummary{
    private:
        int txnNo;
        int cardNo;
        int amount;

    public:
        PurchaseTransactionSummary(int txnNo, int cardNo, int amount){
            this->txnNo = txnNo;
            this->cardNo = cardNo;
            this->amount = amount;
        }

        int getTransactionNo(){
            return txnNo;
        }

        int getCardNo(){
            return cardNo;
        }

        int getAmount(){
            return amount;
        }
};