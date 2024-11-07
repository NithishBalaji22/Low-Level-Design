#pragma once
#include <iostream>
#include <vector>
#include "Account.hpp"
using namespace std;

class Reservation;
class Guest{
    private:
        string name;
        string phoneNo;
        string mailId;
        Account* account;
        vector<Reservation*> reservations;

    public:
        Guest(string name, string phoneNo, string mailId, Account* account){
            this->name = name;
            this->phoneNo = phoneNo;
            this->mailId = mailId;
            this->account = account;
        }

        Account* getAccount(){
            return account;
        }

        void addReservation(Reservation* reservation){
            reservations.emplace_back(reservation);
        }

        void showBalance(){
            cout<<"Balance: "<<account->getBalance()<<endl;
        }
};