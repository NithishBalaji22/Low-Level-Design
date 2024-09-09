#pragma once
#include<iostream>
using namespace std;

class MenuItem;
class OrderItems{
    private:
        MenuItem* item;
        int quantity;

    public:
        OrderItems(MenuItem* item, int quantity){
            this->item = item;
            this->quantity = quantity;
        } 

        MenuItem* getItem(){
            return item;
        }

        int getQuantity(){
            return quantity;
        }
};