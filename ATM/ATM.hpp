#pragma once
#include <bits/stdc++.h>
#include "Account.hpp"
#include "TransactionInterface.hpp"
#include "Credit.hpp"
#include "Debit.hpp"
#include "MiniStatement.hpp"
#include "PaymentFlow.hpp"
#include "TransferMoney.hpp"
using namespace std;

class ATM{
    private:
        static ATM* instance;
        static int paymentId;
        vector<int> bills;
        vector<int> denomination;
        priority_queue<pair<int, MiniStatement*>> miniStatements;
        map<int, Account*> accounts;
        ATM(){
            bills = {100, 500, 100};
            denomination = {20, 100, 300};
            accounts = map<int, Account*>();
            miniStatements = priority_queue<pair<int, MiniStatement*>>();
        }

    public:
        static ATM* getInstance();
        void showCustomerDetails();
        void addMiniStatement(MiniStatement* ministatement);
        void addAccount(Account* account);
        void checkBalance();
        void withdrawalMoney();
        void transferMoney();
        void ministatementLookUp();        
};