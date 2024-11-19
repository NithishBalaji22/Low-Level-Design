#include <iostream>
#include "PaymentFlowInterface.hpp"
#include "PayToFriend.hpp"
#include "PayToMerchant.hpp"
using namespace std;

/*
Pattern Category:  Its a behavioral Pattern

Why its required and when to use it :
    When you want all the class to follow the specific steps to process the task but also need to provide the flexibility that each class can have their own logic in that specific steps
*/

int main(){
    PaymentFlow* payment1 = new PayToFriend();
    payment1->sendMoney();

    PaymentFlow* payment2 = new PayToMerchant();
    payment2->sendMoney();
}