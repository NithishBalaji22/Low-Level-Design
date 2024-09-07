#pragma once
#include<iostream>
#include<vector>
#include "OrderItems.hpp"
using namespace std;

class User{
    private:
        string id;
        string name;
        string email;
        string phoneNumber;
        string passWord;
        vector<OrderItems*> items;

    public:
        User(string id, string name, string email, string phoneNumber, string passWord){
            this->id = id;
            this->name = name;
            this->email = email;
            this->phoneNumber = phoneNumber;
            this->passWord = passWord;
        }

        string getUserId(){
            return id;
        }

        string getUserName(){
            return name;
        }

        string getUserLast4DigitPhoneNumber() {
            return phoneNumber.substr(phoneNumber.size() - 4);
        }

        void addItem(const vector<OrderItems*> newItems) {
            items.insert(items.end(), newItems.begin(), newItems.end());
        }

        vector<OrderItems*> getItems(){
            return items;
        }
};
