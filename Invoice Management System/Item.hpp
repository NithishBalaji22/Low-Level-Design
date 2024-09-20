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

        int getId(){
            return id;
        }

        string getName(){
            return name;
        }

        int getSellingPrice(){
            return sp;
        }

        int getCostPrice(){
            return cp;
        }
        
        int getNetProfit(){
            return netProfit;
        }

        int getQuantity(){
            return itemQuantity;
        }

        void decrementQuantity(int quantity){
            itemQuantity -= quantity;
        }

        void incrementQuantity(int quantity){
            itemQuantity += quantity;
        }

        void setSellingPrice(int price){
            sp = price;
        }

        void setCostProce(int price){
            cp = price;
        }

        void incrementProfit(int quantity) {
            netProfit += (sp - cp) * quantity;
        }

};