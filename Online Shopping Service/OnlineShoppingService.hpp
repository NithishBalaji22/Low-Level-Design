#pragma once
#include<bits/stdc++.h>
using namespace std;

#include"Order.hpp"
#include "OrderItems.hpp"
#include "Product.hpp"
#include"ShoppingCart.hpp"
#include "User.hpp"

class OnlineShoppingService{
    private:
        string ORDER_ID_PREFIX = "ODR";
        static OnlineShoppingService* instance;
        unordered_map<string, User*> users;
        unordered_map<string, Product*> products;
        unordered_map<string, Order*> orders;

        OnlineShoppingService(){
            users = unordered_map<string, User*>();
            products = unordered_map<string, Product*> ();
            orders = unordered_map<string, Order*>();
        }

        public:
            static OnlineShoppingService* getInstance();
            void registerUser(User* user);
            void addProduct(Product* product);
            User* getUser(string userId);
            Product* getProduct(string productId);
            Order* placeOrder(User* user, ShoppingCart* cart); 
            string generateOrderId(User* user); 
            Order* getOrder(string orderId);
            
};