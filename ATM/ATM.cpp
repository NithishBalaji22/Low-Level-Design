#include "ATM.hpp"

// bool depositCash(string accountNumber, double amount);
// string generateTransactionId();

bool ATM::authenticateCard(Card* card){
    string pin;
    cout<<"Please Enter your PIN: ";
    cin>>pin;

    if(card->getPin() == pin) return true;
    return false;
}

double ATM::checkBalance(string accountNumber){
    Account* account = bankingSystem->getAccount(accountNumber);
    if(account != nullptr){
        return account->getBalance();
    }

    cout<<"We couldnt find your account in our database sorry for the inconvinience caused"<<'\n';
    return 0;
}


bool ATM::withdrawalCash(string accountNumber, double amount){
    Account* account = bankingSystem->getAccount(accountNumber);
    if(account != nullptr){
        Transaction* newTransaction = new WithdrawalTransaction(generateTransactionId(), account, amount);
        //From bankingService only you are processing the transaction 
        //newTransaction->execute();
        bankingSystem->processTransaction(newTransaction);
        dispenser->disPenseCash(amount);
        return true;
    }

    cout<<"Due to some technical giltch we couldnt process your request sorry for the inconvience caused from our side"<<'\n';
    return false;
}

bool ATM::depositCash(string accountNumber, double amount){
    Account* account = bankingSystem->getAccount(accountNumber);
    if(account != nullptr){
        Transaction* newTransaction = new DepositTransaction(generateTransactionId(), account, amount);
        //From bankingService only you are processing the transaction 
        //newTransaction->execute();
        bankingSystem->processTransaction(newTransaction);
        return true;
    }

    cout<<"Due to some technical giltch we couldnt process your request sorry for the inconvience caused from our side"<<'\n';
    return false;
}

string ATM::generateTransactionId(){
    string id = to_string (rand() % 100);
    return id;
}