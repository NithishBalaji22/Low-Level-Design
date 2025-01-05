#pragma once
#include <iostream>
#include <vector>
#include "CabDriverRideSummary.hpp"
using namespace std;

class RideSummaryStrategy;
class Cab{
    private:
        int id;
        string location;
        int totalFareCollected;
        int totalZulaCommission;
        vector<RideSummaryStrategy*> rides;

    public:
        Cab(int id, string location){
            this->id = id;
            this->location = location;
            totalFareCollected = 0;
            totalZulaCommission = 0;
            rides = vector<RideSummaryStrategy*>();
        }

        int getId(){
            return id;
        }

        string getLocation(){
            return location;
        }

        void setLocation(string location){
            this->location = location;
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
        
        vector<RideSummaryStrategy*> getRides(){
            return rides;
        }
};