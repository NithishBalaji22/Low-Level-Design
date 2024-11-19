#include "Account.hpp"
#include "Transaction.hpp"
#include "Transaction_Credit.hpp"
#include "Transaction_Debit.hpp"
#include <iostream>
using namespace std;

int main(){
    Account* account = new Account(1111, 2812, 100);
    cout<<account->getBalance()<<endl;

    Transaction* debit = new Debit(1, account, 10);
    debit->execute();

    cout<<account->getBalance();
}