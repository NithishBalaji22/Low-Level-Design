#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "Customer.hpp"
#include "DeliveryAgent.hpp"
#include "MenuItem.hpp"
#include "Order.hpp"
#include "OrderItem.hpp"
#include "Restaurant.hpp"

class OnlineFoodDeliverySystem{
    private:
        string ORDER_ID_PREFIX = "ORD";
        static OnlineFoodDeliverySystem* instance;
        unordered_map<string, Customer*> customers;
        unordered_map<string, Restaurant*> restaurants;
        unordered_map<string, DeliveryAgent*> deliveryAgents;
        unordered_map<string, Order*> orders;
        OnlineFoodDeliverySystem(){
            customers = unordered_map<string, Customer*>();
            restaurants = unordered_map<string, Restaurant*>();
            deliveryAgents = unordered_map<string, DeliveryAgent*>();
            orders = unordered_map<string, Order*>();
        }

    public:
        static OnlineFoodDeliverySystem* getInstance();
        void registerCustomers(string customerId, Customer* customer);
        void registerRestaurants(string restaurantId, Restaurant* restaurant);
        void registerDeliveryAgents(string agentId, DeliveryAgent* agent);
        void addOrders(string orderId, Order* order);
        vector<Restaurant*> getAvailableRestaurants();
        vector<MenuItem*> getRestaurantMenu(string restaurantId);
        Order* placeOrder(string customerId, string restaurantId, vector<OrderItems*> items);
        void cancelOrder(string orderId);
        void assignAgent(Order* order);
        void updateOrderStatus(string orderId, OrderStatus status);
        string generateOrderId(Customer* customer);
        vector<DeliveryAgent*> getDeliveryAgents();
};


