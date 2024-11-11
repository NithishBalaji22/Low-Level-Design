#pragma once
#include <iostream>
using namespace std;

class Product{
    private:
        int productId;
        string productName;
        int quantity;
        int price;

    public:
        Product(int productId, string productName, int quantity, int price){
            this->productId = productId;
            this->productName = productName;
            this->quantity = quantity;
            this->price = price;
        }

        int getProductId(){
            return productId;
        }

        int getProductCost(){
            return price;
        }

        string getProductName(){
            return productName;
        }

        int getQuantity(){
            return quantity;
        }

        void decrementQuantity(int quantity){
            this->quantity -= quantity;
        }

        void updateQuantity(int quantity){
            this->quantity += quantity;
        }
};