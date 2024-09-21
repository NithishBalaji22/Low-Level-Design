#pragma once
#include<iostream>
using namespace std;

class Customer{
    private:
        int id;
        string name;
        string emailId;
        string phoneNumber;
        string drivingLicenseNum;
        int balance;

    public:
        Customer(int id, string name, string emailId, string phoneNumber, string drivingLicense, int balance){
            this->id = id;
            this->name = name;
            this->emailId = emailId;
            this->phoneNumber = phoneNumber;
            drivingLicenseNum = drivingLicense;
            this->balance = balance;
        }

        int getId(){
            return id;
        }

        int getBalance(){
            return balance;
        }

        string getName(){
            return name;
        }

        void debit(int amount){
            balance -= amount;
        }

        void credit(int amount){
            balance += amount;
        }

};