#pragma once
#include <bits/stdc++.h>
#include "Customer.hpp"
#include "DeliveryAgent.hpp"
#include "MenuItem.hpp"
#include "Order.hpp"
#include "Restaurant.hpp"
#include "OrderStatus.hpp"   
#include "Transaction_Interface.hpp"
#include "Transaction_Debit.hpp"
#include "Transaction_Credit.hpp"
#include "OrderItems.hpp"
using namespace std;

class OnlineFoodDeliverySystem{
    private:
        static OnlineFoodDeliverySystem* instance;
        static int orderId;
        static int transactionId;
        unordered_map<string, Restaurant*> restaurentMaps;
        unordered_map<string, Customer*> customerMaps;
        unordered_map<string, DeliveryAgent*> agentMaps;
        unordered_map<int, Order*> ordersMap;
        vector<DeliveryAgent*> agents;
        OnlineFoodDeliverySystem(){
            orderId = 1;
            transactionId = 1;
            restaurentMaps = unordered_map<string, Restaurant*>();
            customerMaps = unordered_map<string, Customer*>();
            agentMaps = unordered_map<string, DeliveryAgent*>();
            ordersMap = unordered_map<int, Order*>();
            agents = vector<DeliveryAgent*>();
        }        

    public:
        static OnlineFoodDeliverySystem* getInstance();
        void registerUser(Customer* user);
        void registerRestaurant(Restaurant* restaurant);
        void registerDeliveryAgent(DeliveryAgent* agent);
        void addOrder(Order* order);
        bool userLogin(Customer* user);
        Order* placeOrder(Customer* user, Restaurant* restaurant);
        void orderSummary(Order* order);
        void deliveredOrder(Order* order);
        int generateOrderId();
        int generateTransactionId();
};