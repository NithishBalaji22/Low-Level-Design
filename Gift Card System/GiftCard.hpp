#pragma once
#include <iostream>
using namespace std;

class GiftCard{
    private:
        int giftCardNo;
        int custID;
        int pin;
        int giftCardBalance;
        bool closeStatus;
        bool block;

    public:
        GiftCard(int giftCardNo, int custID, int pin, int giftCardBalance = 0){
            this->giftCardNo = giftCardNo;
            this->custID = custID;
            this->pin = pin;
            this->giftCardBalance = giftCardBalance;
            closeStatus = false;
            block = false;
        }

        int getGiftCardNo(){
            return giftCardNo;
        }

        int getCustID(){
            return custID;
        }

        int getPin(){
            return pin;
        }

        int getGiftCardBalance(){
            return giftCardBalance;
        }

        void topUp(int amount){
            giftCardBalance += amount;
        }

        void purchase(int amount){
            giftCardBalance -= amount;
        }

        void closeGiftCard(){
            giftCardBalance = 0;
            closeStatus = true;
        }

        void blockGiftCard(){
            block = true;
        }

        bool getGiftCardCloseStatus(){
            return closeStatus;
        }

        bool isGiftCardActive(){
            return block;
        }
};