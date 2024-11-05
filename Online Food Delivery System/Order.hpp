#pragma once
#include <iostream>
#include <vector>
#include "OrderStatus.hpp"
using namespace std;

class Customer;
class DeliveryAgent;
class Restaurant;
class MenuItem;
class OrderItem;
class Order{
    private:
        int id;
        Customer* user;
        Restaurant* restaurant;
        DeliveryAgent* agent;
        OrderStatus status;
        int amount;
        vector<OrderItem*> orderItems;
    
    public:
    Order(int id, Customer* user, Restaurant* restaurant, DeliveryAgent* agent, vector<OrderItem*> orderItems, int amount){
        this->id = id;
        this->user = user;
        this->restaurant = restaurant;
        this->agent = agent;
        this->orderItems = orderItems;
        this->amount = amount;
        status = OrderStatus::PREPARING;
    }

    int getOrderId(){
        return id;
    }

    void delivered(){
        status = OrderStatus::DELIVERED;
    }

    Restaurant* getRestaurant(){
        return restaurant;
    }

    vector<OrderItem*> getOrderItem(){
        return orderItems;
    }

    int getAmount(){
        return amount;
    }

    DeliveryAgent* getAgent(){
        return agent;
    }

    Customer* getUser(){
        return user;
    }
};