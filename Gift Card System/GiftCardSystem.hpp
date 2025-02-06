#pragma once
#include <bits/stdc++.h>
#include "Account.hpp"
#include "Customer.hpp"
#include "GiftCard.hpp"
#include "TransactionInterface.hpp"
#include "Credit.hpp"
#include "Debit.hpp"
#include "PurchaseTransactionSummary.hpp"
using namespace std;

class GiftCardSystem{
    private:
        static GiftCardSystem* instance;
        int transactionID;
        int customerID;
        int giftCardNo;
        int giftCardAmount;
        map<int, Account*> accountsMap;
        map<int, GiftCard*> giftCardMap;
        map<int, PurchaseTransactionSummary*> purchaseTransactionSummaryMap;
        unordered_map<int, Customer*> customerMap;
        GiftCardSystem(){
            transactionID = 1;
            customerID = 4;
            giftCardNo = 1;
            giftCardAmount = 2500;
            accountsMap = map<int, Account*>();
            giftCardMap = map<int, GiftCard*>();
            purchaseTransactionSummaryMap = map<int, PurchaseTransactionSummary*>();
            customerMap = unordered_map<int, Customer*>();
            initializeAccountAndCustomer();
        }

    public:
        static GiftCardSystem* getInstance();
        void initializeAccountAndCustomer();
        void createCustomer();
        void accountSummary();
        void createGiftCard();
        void giftCardSummary();
        void purchaseTransactionSummary();
        void topUpGiftCard();
        void closeGiftCard();
        void purchaseItem();
        // void blockCard();
        // void unblockCard();
        int generateTransactionID();
        int generateGiftCardNo();
        int generateCustomerID();
};
