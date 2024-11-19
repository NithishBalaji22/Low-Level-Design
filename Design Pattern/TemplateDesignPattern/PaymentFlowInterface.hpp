#pragma once
#include <iostream>
using namespace std;

class PaymentFlow{
    public:
        virtual void validateRequest() = 0;
        virtual void debitMoney() = 0;
        virtual void calculateFees() = 0;
        virtual void creditMoney() = 0;

        void sendMoney(){
            //Step 1
            validateRequest();

            //Step2
            debitMoney();

            //Step 3
            calculateFees();

            //Step 4
            creditMoney();
        }
};
