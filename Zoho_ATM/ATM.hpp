#include <bits/stdc++.h>
#include <iomanip>
#include "Card.hpp"
#include "TransactionInterface.hpp"
#include "CreditTransaction.hpp"
#include "DebitTransaction.hpp"
#include "MiniStatement.hpp"
using namespace std;

class ATM{
    private:
        static int transactionId;
        vector<int> notes;
        vector<int> denomination;
        priority_queue<pair<int, MiniStatement*>> miniStatement;
        unordered_map<int, Account*> accounts;

    public:
        ATM(vector<int> noteCounts){
            transactionId = 1;
            miniStatement = priority_queue<pair<int, MiniStatement*>>();
            notes = vector<int>(3, 0); // 1000 500 100
            denomination = {1000, 500, 100};
            for(int i= 0; i<3; i++){
                notes[i] = noteCounts[i];
            }
        }

        void addAccount(vector<Account*> a){
            for(auto account : a){
                accounts[account->getAccountNum()] = account;
            }
        }

        void showCustomerDetails(){
            cout<<"Acc No\tAccount Holder\tAccount Balance"<<endl;
            for(auto [accountNum, account] : accounts){
                cout<<account->getAccountNum()<<'\t'<<account->getAcHolderName()<<'\t'<<"              "<<account->getBalance()<<endl;           
            }
        }

        int display(){
            int option;
            cout<<"Please Select An Option: "<<endl;
            cout<< "1. Check Balance"<<endl;
            cout<< "2. Withdrawal"<<endl;
            cout<< "3. Transfer Amount"<<endl;
            cin>>option;
            return option;
        }

        bool authenticateUser(Card* card){
            int pin;
            cout<<"Enter the PIN: ";
            cin>>pin;
            if(card->getPin() == pin){
                int option = display();
                Account* account = nullptr;
                switch (option){
                    case 1:
                        account = card->getAccount();
                        checkBalance(account);
                        break;

                    case 2:
                        account = card->getAccount();
                        withdrawal(account);
                        break;

                    case 3:
                        account = card->getAccount();
                        int toAccount;
                        cout<<"Enter the account number to which you want to send: ";
                        cin>>toAccount;
                        if(accounts.find(toAccount) != accounts.end()){
                            Account* _toAccount = accounts[toAccount];
                            int amount;
                            cout<<"Enter the amount you have to send: ";
                            cin>>amount;

                            if(amount < 100){
                                cout<<"Minimum amount to transfer is 100 and you are tryig to transfer less than 100 so we cannot proceed"<<endl;
                                return false;
                            }else if (amount > 10000){
                                cout<<"The daily limit to transfer fund is 10,000 but you have enter above 10,000 so we cannot proceed"<<endl;
                                return false;
                            }else if (account->getBalance() < amount){
                                cout<<"Insufficient Funds"<<endl;
                                return false;
                            }

                            transferMoney(account, _toAccount, amount);
                        }else{
                            cout<<"We cannot find the account"<<endl;
                            return false;
                        }
                        break;
                    default:
                        cout<<"Invalid Choice retry again"<<endl;
                        return false;
                }
                return true;
            }
            cout<<"Incorrect PIN remove the card and try again"<<endl;
            return false;
        }

        void checkBalance(Account* account){
            cout<<"Balance: "<<account->checkBalance()<<endl;
        }

        void withdrawal(Account* account){
            int amount;
            cout<<"Daily Maximum Limit is $10,000"<<endl;
            cout<<"Enter the Amount: ";
            cin>>amount;
            if(account->getBalance() < amount){
                cout<<"Insufficient Funds"<<endl;
                return;
            }
            vector<int> taken(3, 0);
            for(int i=0; i<3; i++){
                int maxTake = amount / notes[i];
                int can_take = min(denomination[i], maxTake);
                amount -= can_take * notes[i];
                taken[i] = can_take;
            }

            if(amount > 0){
                cout<<"Out of Service";
                return;
            }

            int transactionId = generateTransactionId();
            Transaction* transaction = new DebitTransaction(transactionId, account, amount);
            transaction->execute(); // Main thing but you forgot to add it man
            MiniStatement* statement = new MiniStatement(transactionId, "Debited" + to_string(amount) + "from the ATM", "Debit", amount);
            miniStatement.push({transactionId, statement});
            for(int i=0; i<3; i++){
                denomination[i] -= taken[i];
            }

            cout<<"Please collect your cash"<<endl;
        }

        void transferMoney(Account* ac1, Account* ac2, int amount){
            if(ac1->getBalance() < amount){
                cout<<"Insufficient Fund"<<endl;
                return;
            }

            int transactionId1 = generateTransactionId();
            int transactionId2 = generateTransactionId();

            Transaction* debitTransaction = new DebitTransaction(transactionId1, ac1, amount);
            Transaction* creditTransaction = new CreditTransaction(transactionId2, ac2, amount);

            debitTransaction->execute();
            creditTransaction->execute();

            MiniStatement* debitStatement = new MiniStatement(transactionId1, "Fund transfer to account " + to_string(ac2->getAccountNum()), "Debit", amount);
            MiniStatement* creditStatement2 = new MiniStatement(transactionId2, "Fund transfer from account " + to_string(ac1->getAccountNum()), "Credit", amount);

            miniStatement.push({transactionId1, debitStatement});
            miniStatement.push({transactionId2, creditStatement2});
        }

        void ministatement(){
            int k= 5;
            cout<<"TransactionId\tTransaction Remarks\tTransaction Type\tTransactionAmount"<<endl;
            auto miniStatementCopy = miniStatement;
            while(k-- && !miniStatementCopy.empty()){
                MiniStatement* statement = miniStatementCopy.top().second;
                miniStatementCopy.pop();
                cout<<statement->getTransactionId()<<'\t'<<statement->getTransactionRemarks()<<"             "<<statement->getTransactionType()<<'\t'<<statement->getTransactionAmount()<<endl;
            }
        }

        int generateTransactionId(){
            return transactionId++;
        }  
};

int ATM::transactionId;
