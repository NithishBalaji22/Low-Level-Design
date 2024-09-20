#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Sales;
class Customer{
    private:
        int id;
        string name;
        int totalPurchaseCost;
        int balance;
        vector<Sales*>purchases;
        static int customerCounter;

    public:
        Customer(string name, int balance){
            id = Customer::customerCounter++;
            this->name = name;
            this->balance = balance;
            totalPurchaseCost = 0;
            purchases = vector<Sales*>();
        } 

        int getId();
        int getBalance();
        string getName();
        int getTotalPurchaseCost();
        vector<Sales*> getPurchases();
        void addToTotalPurchaseCost(int amount);
        void addSales(Sales* sale);
        void creditBalance(int amount);
        void debitBalance(int amount);        
};
