#pragma once
#include <iostream>
#include <vector>
#include "CabDriverRideSummary.hpp"
using namespace std;

class RideSummaryStrategy;
class CabDriver{
    private:
        int id;
        string name;
        int password;
        int age;
        int totalFareCollected;
        int totalZulaCommission;
        vector<RideSummaryStrategy*> rides;
    
    public:
        CabDriver(int id, string name, int password, int age){
            this->id = id;
            this->name = name;
            this->password = password;
            this->age = age;
            totalFareCollected = 0;
            totalZulaCommission = 0;
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
            totalFareCollected += ride->getFare();
            totalZulaCommission += ride->getZulaCommission();
            rides.emplace_back(ride);
        }

        int getTotalFareCollected(){
            return totalFareCollected;
        }

        int getTotalZulaCommission(){
            return totalZulaCommission;
        }

        vector<RideSummaryStrategy*> getDriverRides(){
            return rides;
        }
};