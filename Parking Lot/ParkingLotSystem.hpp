#pragma once
#include<bits/stdc++.h>
using namespace std;

#include"Floor.hpp"
#include"ParkingSpot.hpp"
#include"Vehicle.hpp"
#include"VehicleType.hpp"

class ParkingLotSystem{
    private:
        static ParkingLotSystem* instance;
        vector<Floor*> floors;
        ParkingLotSystem(){
            floors = vector<Floor*>();
        }

    public:
        static ParkingLotSystem* getInstance();
        void addFloors(Floor* floor);
        bool parkVehicle(Vehicle* vehicle);
        bool unParkVehicle(Vehicle* vehicle);
        void displayAvailability();
};