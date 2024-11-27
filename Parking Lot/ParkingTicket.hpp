#pragma once
#include <iostream>
#include <chrono>
#include "Vehicle.hpp"
using namespace std;

class ParkingTicket{
    private:
        chrono::time_point<chrono::high_resolution_clock> start;
        Vehicle* vehicle;

    public:
        ParkingTicket(chrono::time_point<chrono::high_resolution_clock> start, Vehicle* vehicle){
            this->start = start;
            this->vehicle = vehicle;
        }

        chrono::time_point<chrono::high_resolution_clock> getStartTime(){
            return start;
        }

        Vehicle* getVehicle(){
            return vehicle;
        }
};