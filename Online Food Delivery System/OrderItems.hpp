#pragma once
#include <iostream>
using namespace std;

class MenuItem;
class OrderItem{
    private:
        MenuItem* item;
        int quantity;

    public:
        OrderItem(MenuItem* item, int quantity){
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