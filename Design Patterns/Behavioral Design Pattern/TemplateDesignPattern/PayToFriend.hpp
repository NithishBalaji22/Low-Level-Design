#pragma once
#include <iostream>
#include "PaymentFlowInterface.hpp"
using namespace std;

class PayToFriend : public PaymentFlow{
    public:
        void validateRequest() override{
            cout<<"Validating Request !!"<<endl;
        }

        void debitMoney() override{
            cout<<"Debiting the money"<<endl;
        }

        void calculateFees() override{
            cout<<"0 percent Fees"<<endl;
        }

        void creditMoney() override{
            cout<<"Credit full amount"<<endl;
        }
};