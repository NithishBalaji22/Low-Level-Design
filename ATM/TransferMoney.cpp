#include "TransferMoney.hpp"
#include "ATM.hpp"
#include "TransactionInterface.hpp"
#include "Credit.hpp"
#include "Debit.hpp"
#include "MiniStatement.hpp"

class Account;
void TransferMoney::validateSender(){
    int pin;
    cout << "Enter the Pin: ";
    cin >> pin;

    if (pin == sender->getPin()){
        cout << "Logging into your account" << endl;
        this_thread::sleep_for(chrono::seconds(3));
        cout << "Welcome To Zoho Bank" << endl;
    }
    else{
        cout << "Invalidate Pin !!" << endl;
        return;
    }
}

void TransferMoney::debit(){
    ATM* atm = ATM::getInstance();
    TransactionInterface *debit = new Debit(id, sender, amount);
    debit->execute();
    MiniStatement* statement = new MiniStatement(id, "Funds transfer to Acc " + to_string(receiver->getAccountNo()), "Debit", amount);
    atm->addMiniStatement(statement);
}

void TransferMoney::credit(){
    ATM* atm = ATM::getInstance();
    TransactionInterface *credit = new Credit(id, receiver, amount);
    credit->execute();
    MiniStatement* statement = new MiniStatement(id, "Funds transfer from Acc " + to_string(sender->getAccountNo()), "Credit", amount);
    atm->addMiniStatement(statement);
}