#pragma once
#include<iostream>
#include "VehicleType.hpp"
#include "Vehicle.hpp"
using namespace std;

class ParkingSpot{
    private:
        int spotNumber;
        Vehicle* parkedVehicle;
        VehicleType vehicleType;

    public:
        ParkingSpot(int spotNumber){
            this->spotNumber = spotNumber;
            vehicleType = VehicleType::CAR; //Default Assuming
        }

        bool parkVehicle(Vehicle* vehicle){
            if(isAvailable() && (vehicle->getVehicleType() == VehicleType::CAR || vehicle->getVehicleType() == VehicleType::TRUCK || vehicle->getVehicleType() == VehicleType::MOTORBIKE)){
                parkedVehicle = vehicle;
                return true;
            }
            cout<<"Parking Spot is not available"<<'\n';
            return false;
        }

        void unParkVehicle(Vehicle* vehicle){
            parkedVehicle = nullptr;
        }

        bool isAvailable(){
            return parkedVehicle == nullptr;
        }

        int getSpotNumber(){
            return spotNumber;
        }

        Vehicle* getParkedVehicle(){
            return parkedVehicle;
        }

        VehicleType getVehicleType(){
            return vehicleType;
        }        
};