#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Order;
class Account;
class Customer{
    private:
        int id;
        string name;
        string mailId;
        string password;
        char location;
        Account* account;
        vector<Order*> orderHistory;
        int totalAmountSpent;

    public:
        Customer(int id, string name, string mailId, string password, char location, Account* account){
            this->id = id;
            this->name = name;
            this->mailId = mailId;
            this->password = password;
            this->account = account;
            this->location = location;
            orderHistory = vector<Order*>();
            totalAmountSpent = 0;
        }

        int getId(){
            return id;
        }

        char getLocation(){
            return location;
        }

        string getMailId(){
            return mailId;
        }

        string getPassword(){
            return password;
        }

        void addOrderAmount(int amount){
            totalAmountSpent += amount;
        }

        void addOrder(Order* order){
            orderHistory.emplace_back(order);
        }

        Account* getAccount(){
            return account;
        }

        vector<Order*> getUserOrderHistory(){
            return orderHistory;
        }

        int getTotalAmountSpent(){
            return totalAmountSpent;
        }
};