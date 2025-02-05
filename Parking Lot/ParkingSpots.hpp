#pragma once
#include <iostream>
#include "VehicleType.hpp"
#include "Vehicle.hpp"
using namespace std;

class Vehicle;
class ParkingSpots{
    private:
        int spotId;
        Vehicle* parkedVehicle;
        VehicleType type;

    public:
        ParkingSpots(int spotId, VehicleType type) : spotId(spotId), type(type) {}

        bool isSpotAvailable(){
            return parkedVehicle == nullptr;
        }   

        bool parkVehicle(Vehicle* vehicle){
            if(isSpotAvailable() && vehicle->getVehicleType() == type){
                this->parkedVehicle = vehicle;
                return true;
            }
            cout<<"Invalid vehicletype or the spot is already occupied"<<endl;
            return false;
        }

        bool unParkVehicle(){
            this->parkedVehicle = NULL;
            return true;
        }

        int getSpotId(){
            return spotId;
        }

        Vehicle* getVehicle(){
            return parkedVehicle;
        }

        VehicleType getSpotType(){
            return type;
        }

        string printSpotType(){
            if(type == VehicleType::CAR) return "CAR";
            else if(type == VehicleType::MOTORBIKE) return "Bike";
            else return "Truck";
        }
};
