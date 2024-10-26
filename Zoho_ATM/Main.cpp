#include "ATM.hpp"
#include "Account.hpp"
#include "Card.hpp"

// Dummy database of accounts
vector<Account*> accounts = {
    new Account(101, "Suresh", 25234),
    new Account(102, "Ganesh", 34123),
    new Account(103, "Magesh", 26100),
    new Account(104, "Naresh", 80000),
    new Account(105, "Harish", 103400)
};

int main() {
    Card* SureshCard = new Card(1111, 2343, accounts[0]);
    Card* GaneshCard = new Card(2222, 5423, accounts[1]);
    Card* MageshCard = new Card(3333, 7854, accounts[2]);
    Card* NareshCard = new Card(4444, 2345, accounts[3]);
    Card* HarishCard = new Card(5555, 1907, accounts[4]);
    
    //Task 1 : Load the cash to ATM
    vector<int> noteCounts = {20, 100, 300};
    ATM* atm = new ATM(noteCounts);

    //Task 2: Show Customer Details
    atm->addAccount(accounts);
    atm->showCustomerDetails();

    //Task 3.1: Check Balance    
    if(atm->authenticateUser(SureshCard)) {
        cout << "Transaction completed successfully." << endl;
    }else{
        cout << "Transaction failed." << endl;
    }   

    // Task 3.1.1: Withdraw Money
    if(atm->authenticateUser(GaneshCard)) {
        cout << "Transaction completed successfully." << endl;
    }else{
        cout << "Transaction failed." << endl;
    }

    //Task 3.2: Transfer Money
    if(atm->authenticateUser(MageshCard)) {
        cout << "Transaction completed successfully." << endl;
    }else{
        cout << "Transaction failed." << endl;
    }

    //Task 3.3 Mini Statement
    atm->ministatement();

    // Clean up memory
    delete atm;
    delete SureshCard;
    delete GaneshCard;
    delete MageshCard;
    delete NareshCard;
    delete HarishCard;
    for (auto* account : accounts) {
        delete account;
    }
    return 0;
}
