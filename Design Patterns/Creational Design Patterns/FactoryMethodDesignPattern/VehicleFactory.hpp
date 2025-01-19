#pragma once
#include <iostream>
#include "Vehicle.hpp"
using namespace std;

class VehicleFactory{
    public:
        static Vehicle* getVehicle(string vehicle){
            if(vehicle == "Car") return new Car();
            else if(vehicle == "Bike") return new Bike();
            else if(vehicle == "Truck") return new Truck();
            return nullptr;
        }
};