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

        void addToTotalPurchaseCost(int amount){
            totalPurchaseCost += amount;
        }

        void creditBalance(int amount){
            balance += amount;
        }

        void debitBalance(int amount){
            balance -= amount;
        }

        int getBalance(){
            return balance;
        }

        string getName(){
            return name;
        }

        int getId(){
            return id;
        }

        int getTotalPurchaseCost(){
            return totalPurchaseCost;
        }

        vector<Sales*> getPurchases(){
            return purchases;
        }

        void addSales(Sales* sale){
            purchases.emplace_back(sale);
        }
};
