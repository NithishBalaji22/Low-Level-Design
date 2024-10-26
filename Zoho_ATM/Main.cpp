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

// Find account by account number
Account* findAccount(int accountNumber) {
    for (auto *account : accounts) {
        if (account->getAccountNum() == accountNumber) {
            return account;
        }
    }
    return nullptr;
}

int main() {
    Card* SureshCard = new Card(1111, 2343, accounts[0]);
    Card* GaneshCard = new Card(2222, 5423, accounts[1]);
    Card* MageshCard = new Card(3333, 7854, accounts[2]);
    Card* NareshCard = new Card(4444, 2345, accounts[3]);
    Card* HarishCard = new Card(5555, 1907, accounts[4]);

    vector<int> noteCounts = {20, 100, 300}; // Starting notes for 1000, 500, 100 denominations
    ATM* atm = new ATM(noteCounts);
    atm->addAccount(accounts);

    if (atm->authenticateUser(SureshCard)) {
        cout << "Transaction completed successfully." << endl;
    } else {
        cout << "Transaction failed." << endl;
    }

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
