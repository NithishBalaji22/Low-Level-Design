#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Customer.hpp"
#include "Item.hpp"
#include "Sales.hpp"

class Store{
    private:
        static Store* instance;
        unordered_map<int, Customer*> customers;
        unordered_map<string, Item*> items;
        unordered_map<int, Sales*> sales;
        Store(){
            customers = unordered_map<int, Customer*>();
            items = unordered_map<string, Item*>();
            sales = unordered_map<int, Sales*>();
        }    

    public:
        static Store* getInstance();
        void registerCustomer(Customer* customer);
        void addItem(Item* item);
        void addSales(Sales* sale);
        void makePurchase(Customer* customer, string itemName, int quantity);
        void makeBulkPurchase(Customer* customer, vector<pair<Item*, int>> bulkPurchase);
        bool transaction(Customer* customer, int amount);
        void displayItems();
        void salesOverview();
};
