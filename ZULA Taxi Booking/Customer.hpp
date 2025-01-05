#pragma once
#include <iostream>
#include <vector>
using namespace std;

class RideSummaryStrategy;
class Customer{
    private:
        int id;
        string name;
        int password;
        int age;
        vector<RideSummaryStrategy*> rides;
    
    public:
        Customer(int id, string name, int password, int age){
            this->id = id;
            this->name = name;
            this->password = password;
            this->age = age;
            rides = vector<RideSummaryStrategy*>();
        }

        int getId(){
            return id;
        }

        string getName(){
            return name;
        }

        int getPassword(){
            return password;
        }

        void addRide(RideSummaryStrategy* ride){
            rides.emplace_back(ride);
        }

        vector<RideSummaryStrategy*> getCustomerRides(){
            return rides;
        }
};