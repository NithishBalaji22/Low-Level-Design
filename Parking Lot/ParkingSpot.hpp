#pragma once
#include <iostream>
#include "VehicleType.hpp"
using namespace std;

class Vehicle;
class ParkingSpot{
    private:
        int spotId;
        VehicleType spotType;
        Vehicle* parkedVehicle;

    public:
        ParkingSpot(int spotId, VehicleType type){
            this->spotId = spotId;
            this->spotType = type;
            parkedVehicle = nullptr;
        }

        int getSpotId(){
            return spotId;
        }

        VehicleType getSpotType(){
            return spotType;
        }

        bool isParkingSpotAvailable(){
            return parkedVehicle == nullptr;
        }

        void parkVehicle(Vehicle* vehicle){
            parkedVehicle = vehicle;
        }

        void unparkVehicle(){
            parkedVehicle = nullptr;
        }

        Vehicle* getVehicle(){
            return parkedVehicle;
        }
};