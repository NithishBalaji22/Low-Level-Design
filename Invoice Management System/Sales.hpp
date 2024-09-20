#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Item;
class Customer;

class Sales{
    private:
        int id;
        static int saleCounter;
        Customer* customer;
        int amountPaid;
        vector<Item*> itemsPurchased;

    public:
        Sales(Customer* customer, vector<Item*> items, int amountPaid){
            id = Sales::saleCounter++;
            this->customer = customer;
            this->amountPaid = amountPaid;
            itemsPurchased = items;
        }

        int getId(){
            return id;
        }

        int getAmountPaid(){
            return amountPaid;
        }

        Customer* getCustomer(){
            return customer;
        }

        vector<Item*> getItemPurchased(){
            return itemsPurchased;
        }

        void addToItemPurchased(Item* item){
            itemsPurchased.emplace_back(item);
        }
};

