#pragma once
#include<iostream>
using namespace std;

class Item{
    private:
        int id;
        string name;
        int sp;
        int cp;
        int netProfit;
        int itemQuantity;
        static int itemCounter;

    public:
        Item(string name, int sp, int cp, int quantity){
            id = Item::itemCounter++;
            this->name = name;
            this->sp = sp;
            this->cp = cp;
            itemQuantity = quantity;
        }

        int getId();
        string getName();
        int getSellingPrice();
        int getCostPrice();        
        int getNetProfit();
        int getQuantity();
        void decrementQuantity(int quantity);
        void incrementQuantity(int quantity);
        void setSellingPrice(int price);
        void setCostProce(int price);
        void incrementProfit(int quantity);

};