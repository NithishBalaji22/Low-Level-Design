#pragma once
#include<iostream>
#include <vector>
#include "Level.hpp"
#include "ParkingSpots.hpp"
#include "Vehicle.hpp"
#include "VehicleType.hpp"
using namespace std;

class ParkingLotSystem{
    private:
        static ParkingLotSystem* instance;
        vector<Level*>levels;
        
        ParkingLotSystem(){
            levels = vector<Level*>();
        }

    public:
        static ParkingLotSystem* getInstance();
        void addLevels(int totalLevels, int spotsPerLevel);
        void parkVehicle(Vehicle* vehicle);
        void unParkVehicle(Vehicle* vehicle);
        void displayAvailability();
};
