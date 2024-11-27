#include "ATM.hpp"
#include "Account.hpp"

ATM* ATM::instance = nullptr;
int ATM::paymentId = 1;
ATM* ATM::getInstance(){
    if(instance == nullptr){
        instance = new ATM();
    }
    return instance;
}

void ATM::addMiniStatement(MiniStatement* ministatement){
    miniStatements.push({ministatement->getId(), ministatement});
}

void ATM::addAccount(Account* account){
    accounts[account->getAccountNo()] = account;        
}

void ATM::showCustomerDetails(){
    cout<<"Acc No\tAccount Holder\tPin Number\tAccount Balance"<<endl;
    for(auto account : accounts){
        Account* a = account.second;
        cout<<a->getAccountNo()<<'\t'<<a->getName()<<"\t\t"<<a->getPin()<<"\t\t"<<a->getBalance()<<endl;
    }
}

void ATM::checkBalance(){
    int accountNo;
    cout<<"Enter Your Account Number: ";
    cin>>accountNo;

    if(accounts.find(accountNo) != accounts.end()){
        Account* account = accounts[accountNo];
        cout<<"Account Number: "<<account->getAccountNo()<<endl;
        cout<<"Account Holder: "<<account->getName()<<endl;
        cout<<"Account Balance: "<<account->getBalance()<<endl;
    }else{
        cout<<"Account Not Found!!"<<endl;
    }
}

void ATM::withdrawalMoney(){
    int accountNo, pin;
    cout<<"Enter Your Account Number: ";
    cin>>accountNo;
    cout<<"Enter Your Pin: ";
    cin>>pin;

    if(accounts.find(accountNo) != accounts.end() && accounts[accountNo]->getPin() == pin){
        Account* account = accounts[accountNo];
        cout<<"Daily Maximum Limit is $10,000"<<endl;
        int amount;
        cout<<"Enter the Amount: ";
        cin>>amount;

        int Amount = amount;

        if(amount > account->getBalance()){
            cout<<"Insufficient Funds !!"<<endl;
            return;
        }

        vector<int> taken(3);
        for(int i=0; i<3; i++){
            int maxTake = amount / bills[i];
            int canTake = min(maxTake, denomination[i]);
            amount -= (canTake * bills[i]);
            taken[i] = canTake;
        }

        if(amount > 0){
            cout<<"Out of Service !!"<<endl;
            return;
        }

        int transactionId = paymentId++;
        TransactionInterface* debit = new Debit(transactionId, account, amount);
        debit->execute();

        MiniStatement* statement = new MiniStatement(transactionId, "Debited " + to_string(Amount) + "From ATM", "Debit", Amount);
        miniStatements.push({statement->getId(), statement});

        for(int i=0; i<3; i++){
            denomination[i] -= taken[i];
        }

        cout<<"Please Collect Your Cash !!"<<endl;

    }else{
        cout<<"Account Not Found !!"<<endl;
    }
}

void ATM::transferMoney(){
    int senderAccNo, receiverAccNo;
    cout<<"Enter your Account and Your Friend Account Number: ";
    cin>>senderAccNo>>receiverAccNo;

    if(accounts.find(senderAccNo) != accounts.end() && accounts.find(receiverAccNo) != accounts.end()){
        Account* sender = accounts[senderAccNo];
        Account* receiver = accounts[receiverAccNo];

        int amount;
        cout<<"Enter the amount you want to transfer: "<<endl;
        cin>>amount;

        if(amount > sender->getBalance()){
            cout<<"Insufficient Funds!!"<<endl;
            return;
        }

        int id = paymentId++;
        PaymentFlow* payment = new TransferMoney(id, sender, receiver, amount);
        payment->execute();
    }else{
        cout<<"Either the sender account number or the receiver account number is not right"<<endl;
    }
}

void ATM::ministatementLookUp(){
    int k= 5;
    cout<<"TransactionId\tTransaction Remarks\tTransaction Type\tTransaction Amt"<<endl;
    auto pq = miniStatements;

    if(miniStatements.size() < 5){
        k = miniStatements.size();
    }

    while(k--){
        MiniStatement* miniStatement = pq.top().second;
        cout<<miniStatement->getId()<<"\t\t"<<miniStatement->getRemark()<<"\t\t"<<miniStatement->getType()<<"\t\t"<<miniStatement->getAmount()<<endl;
        pq.pop();
    }
}