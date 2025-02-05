#pragma once
#include <iostream>
#include "VehicleType.hpp"
using namespace std;

class Vehicle{
    private:
        string licensePlate;
        VehicleType type;

    public:
        Vehicle(string licensePlate, VehicleType type) : licensePlate(licensePlate), type(type) {}

        string getLicensePlate(){
            return licensePlate;
        }

        VehicleType getVehicleType(){
            return type;
        }
};