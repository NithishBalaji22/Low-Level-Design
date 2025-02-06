#pragma once
#include <iostream>
#include <unordered_map>
#include "GiftCard.hpp"
using namespace std;

class Account;
class Customer{
    private:
        int customerID;
        Account* account;
        unordered_map<int, GiftCard*> giftCards;

    public:
        Customer(int customerID, Account* account){
            this->customerID = customerID;
            this->account = account;
            giftCards = unordered_map<int, GiftCard*>();
        }

        int getCustomerID(){
            return customerID;
        }

        Account* getCustomerAccount(){
            return account;
        }

        void addGiftCard(GiftCard* card){
            giftCards[card->getGiftCardNo()] = card;
        }

        bool doesCustomerHasGiftCard(){
            return giftCards.size() > 0;
        }

        GiftCard* getGiftCard(int giftCardNo){
            if(giftCards.find(giftCardNo) != giftCards.end()){
                GiftCard* card = giftCards[giftCardNo];
                return card;
            }

            cout<<"Gift Card for this cardno is not available"<<endl;
            return nullptr;
        }
};
