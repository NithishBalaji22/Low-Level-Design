#pragma once
#include<iostream>
using namespace std;

class User{
    private:
        int id;
        string name;
        string emailId;
        string phoneNum;
        string location;
        int balance;
        static int Counter;

    public:
        User(string name, string emailId, string phoneNum, int balance, string location){
            id = User::Counter++;
            this->name = name;
            this->emailId = emailId;
            this->phoneNum = phoneNum;
            this->balance = balance;
            this->location = location;
        }
        int getId();
        string getName();
        string getEmail();
        string getLocation();
        int getBalance();
        void debitAmount(int amount);
};