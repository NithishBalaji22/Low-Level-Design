#pragma once
#include<iostream>
using namespace std;

class Product{
    private:
        string productId;
        string productName;
        string description;
        double productPrice;
        int quantity;

    public:
        Product(string productId, string productName, string description, double productPrice, int quantity){
            this->productId = productId;
            this->productName = productName;
            this->description = description;
            this->productPrice = productPrice;
            this->quantity = quantity;
        }

        void setProductPrice(double price){
            productPrice = price;
        }

        bool isAvailable(int Quantity){
            return Quantity <= quantity;
        }

        void increaseQuantity(int Quantity){
            quantity += Quantity;
        }

        void decreaseQuantity(int Quantity){
            quantity -= Quantity;
        }

        string getProductId(){
            return productId;
        }

        string getProductName(){
            return productName;
        }

        double getProductPrice(){
            return productPrice;
        }

        int getQuantity(){
            return quantity;
        }
};