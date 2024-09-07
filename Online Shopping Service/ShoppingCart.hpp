#pragma once
#include<unordered_map>
#include<iostream>
#include "OrderItems.hpp"
using namespace std;

class ShoppingCart{
    private:
        unordered_map<string, OrderItems*> items;
    
    public:
        ShoppingCart(){
            items = unordered_map<string, OrderItems*>();
        }

        void addToCart(Product* product, int quantity){
            string productId = product->getProductId();
            //If the product already in the cart then the product has been again added so we are updating the quantity according to that thing
            if(items.find(productId) != items.end()){
                items.at(productId)->updateQuantity(quantity);
                return;
            }   
            items.insert({productId, new OrderItems(product, quantity)});             
        }

        void decreaseTheQuantity(Product* product, int quantity){
            string productId = product->getProductId();
            if(items.find(productId) != items.end()){
                items.at(productId)->decreaseQuantity(quantity);
            }else{
                cout<<"The item is not in the cart try adding in the cart and then look into this function again Thank you !"<<'\n';
            }
            return;
        }

        void removeItem(Product* product){
            string productId = product->getProductId();
            if(items.find(productId) != items.end()){
                items.erase(productId);
            }else{
                cout<<"The Product which you are looking at is not in the cart!"<<'\n';
            }
            return;
        }

        vector<OrderItems*> getOrderItems(){
            vector<OrderItems*> v;
            for(auto it : items){
                v.push_back(it.second);
            }
            return v;
        }

        void cartClear(){
            items.clear();
        }
};