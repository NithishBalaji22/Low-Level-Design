#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Order;
class DeliveryAgent{
    private:
        int id;
        string name;
        char location;
        int totalEarnings;
        vector<Order*> delivery;
        bool availability;

    public:
        DeliveryAgent(int id, string name, char location){
            this->id = id;
            this->name = name;
            this->location = location;
            availability = true;
            delivery = vector<Order*>();
        }

        int getId(){
            return id;
        }

        string getName(){
            return name;
        }

        bool getAvailability(){
            return availability;
        }

        void unavailable(){
            availability = false;
        }

        void available(){
            availability = true;
        }

        char getLocation(){
            return location;
        }

        void setLocation(char location){
            this->location = location;
        }

        void addOrder(Order* order){
            delivery.emplace_back(order);
        }

        void addFair(int amount){
            totalEarnings += amount;
        }
};