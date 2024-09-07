#pragma once
#include<bits/stdc++.h>
#include "Product.hpp"
using namespace std;

class OrderItems{
    private:
        Product* product;
        int quantity;

    public: 
        OrderItems(Product* product, int quantity){
            this->product = product;
            this->quantity = quantity;
        }

        Product* getProduct(){
            return product;
        }

        int getQuantity(){
            return quantity;
        }

        void updateQuantity(int quantity){
            this->quantity += quantity;
        }

        void decreaseQuantity(int quantity){
            this->quantity -= quantity;
        } 
};