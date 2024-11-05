#pragma once
#include <bits/stdc++.h>
#include <thread>
#include "Account.hpp"
#include "Car.hpp"
#include "Pass.hpp"
#include "Payment.hpp"
#include "PaymentCredit.hpp"
#include "PaymentDebit.hpp"
#include "Toll.hpp"
#include "User.hpp"
using namespace std;

class TollPaymentProcessing{
    private:
        static int paymentId;
        static int passId;
        static TollPaymentProcessing* instance;
        unordered_map<char, Toll*> tollMap;
        unordered_map<int, Pass*> totalPassList;
        unordered_map<int, User*> userMap;
        unordered_map<string, Car*> carMap;
        TollPaymentProcessing(){
            paymentId = 1;
            passId = 1;
            tollMap = unordered_map<char, Toll*>();
            totalPassList = unordered_map<int, Pass*>();
            userMap = unordered_map<int, User*>();
            carMap = unordered_map<string, Car*>();
        }

    public:
        static TollPaymentProcessing* getInstance();
        void registerToll(Toll* toll);
        void addUser(User* user);
        void addCar(Car* car);
        void startJouney(Car* car);
        void reachedTollAndMakePayment(char tollLocation, Car* car);
        void journeyOverView(Car* car);
        int generatePaymentId();
        int generatePassId();
};