#pragma once
#include<bits/stdc++.h>
using namespace std;

class Customer;
class Restaurant;
class DeliveryAgent;
class MenuItem;
class OrderItems;

enum OrderStatus{
    ORDER,
    PREPARING,
    OUT_FOR_DELIVERY,
    PENDING,
    CANCELLED,
    CONFIRMED
};

class Order{
    private:
        string orderId;
        Customer* customer;
        Restaurant* restaurant;
        DeliveryAgent* agent;
        unordered_map<string, OrderItems*> items;
        OrderStatus status;

    public:
        Order(string orderId, Customer* customer, Restaurant* restaurant){
            this->orderId = orderId;
            this->customer = customer;
            this->restaurant = restaurant;
            this->items = unordered_map<string, OrderItems*>();
            status = OrderStatus::PENDING;
        }

        string getOrderId(){
            return orderId;
        }

        void setOrderStatus(OrderStatus newStatus){
            status = newStatus;
        }

        void addItem(string itemName, OrderItems* item){
            items.insert({itemName, item});
        }

        void removeItem(string itemName){
            items.erase(itemName);
        }

        void assignDeliveryAgent(DeliveryAgent* agent){
            this->agent = agent;
        }

        OrderStatus getOrderStatus(){
            return status;
        }

        vector<OrderItems*> getOrderItems(){
            vector<OrderItems*> v;
            for(auto it : items){
                v.emplace_back(it.second);
            }
            return v;
        }
};