#pragma once
#include<iostream>
#include<vector>
#include "OrderItems.hpp"
using namespace std;

class Product;
class User;

enum OrderStatus{
    ORDER,
    SHIPPING,
    PENDING,
    DELIVERED, 
    CANCELLED
};


class Order{
    private:
        string orderId;
        User* user;
        vector<OrderItems*>items;
        OrderStatus status;
        double totalPrice;

    public:
        Order(string orderId, User* user, vector<OrderItems*> items){
            this->orderId = orderId;
            this->user = user;
            this->items = items;
            totalPrice = calTotalPrice(items);
            status = OrderStatus::PENDING;
        }

        double calTotalPrice(vector<OrderItems*> items){
            double total= 0;
            for(OrderItems* item : items){
                total += item->getProduct()->getProductPrice() * item->getQuantity();
            }
            return total;
        }
        
        string getOrderId(){
            return orderId;
        }

        User* getUser(){
            return user;
        }

        vector<OrderItems*> getOrderItems(){
            return items;
        }

        OrderStatus getOrderStatus(){
            return status;
        }

        double getTotalPrice(){
            return totalPrice;
        }
};