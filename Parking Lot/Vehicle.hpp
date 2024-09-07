#pragma once
#include<iostream>
#include "VehicleType.hpp"
using namespace std;

class Vehicle{
    private:
        string licensePlate;
        VehicleType vehicleType;

    public:
        Vehicle(string licensePlate, VehicleType vehicleType){
            this->licensePlate = licensePlate;
            this->vehicleType = vehicleType;
        }

        string getLicensePlate(){
            return licensePlate;
        }

        VehicleType getVehicleType(){
            return vehicleType;
        }
};