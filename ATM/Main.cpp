#include <iostream>
#include "ATM.hpp"
#include "Account.hpp"
using namespace std;

int main(){
    // Task 1: Load cash to ATM
    ATM* atm = ATM::getInstance();

    // Creating Accounts
    //vector<Account*> accounts = {new Account(101, "Suresh", 2343, 25234),new Account(102, "Ganesh", 5432, 34123), new Account(103, "Magesh", 7854, 26100), new Account(104, "Naresh", 2345, 80000), new Account(105, "Harish", 1907, 103400)};
    Account* suresh = new Account(101, "Suresh", 2343, 25234);
    Account* Ganesh = new Account(102, "Ganesh", 5432, 34123); 
    Account* Magesh = new Account(103, "Magesh", 7854, 26100);
    Account* Naresh = new Account(104, "Naresh", 2345, 80000); 
    Account* Harish = new Account(105, "Harish", 1907, 103400);

    atm->addAccount(suresh);
    atm->addAccount(Ganesh);
    atm->addAccount(Magesh);
    atm->addAccount(Naresh);
    atm->addAccount(Harish);

    // Task 2 : Show Customer Details
    atm->showCustomerDetails();

    // Task 3 : Show ATM Process
    bool flag = true;
    while(flag){
        cout<<"Options"<<endl;
        cout<<"1. Check Balance\n2. Withdraw Money\n3. Transfer Money\n4. Mini Statement\n5. Break"<<endl;
        int option;
        cout<<"Enter the option number: ";
        cin>>option;

        switch(option){
            case 1:
                atm->checkBalance();
                break;
            case 2:
                atm->withdrawalMoney();
                break;
            case 3:
                atm->transferMoney();
                break;
            case 4:
                atm->ministatementLookUp();
                break;
            case 5:
                flag = false;
                break;
            default:
                cout<<"Choosen a wrong option try again!!"<<endl;
                break;
        }
    }    
}