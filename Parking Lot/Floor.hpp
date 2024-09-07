#pragma once
#include<iostream>
#include<vector>
#include"ParkingSpot.hpp"
#include "VehicleType.hpp"
using namespace std;

class Vehicle;

class Floor{
    private:
        int floorNo;
        vector<ParkingSpot*> parkingSpots;

    public:
        Floor(int floorNo, int totalParkingSpots){
            this->floorNo = floorNo;
            parkingSpots = vector<ParkingSpot*>(totalParkingSpots);
            for(int i=0; i<totalParkingSpots; i++){
                parkingSpots[i]= new ParkingSpot(i);
            }
        }

        bool parkVehicle(Vehicle* vehicle){
            for(ParkingSpot* spot : parkingSpots){
                if(spot->isAvailable() && (vehicle->getVehicleType() == VehicleType::CAR || vehicle->getVehicleType() == VehicleType::TRUCK || vehicle->getVehicleType() == VehicleType::MOTORBIKE)){
                    spot->parkVehicle(vehicle);
                    return true;
                }
            }
            cout<<"Sorry for the inconvinience parking spots is unavailable"<<'\n';
            return false;
        }

        bool unparkVehicle(Vehicle* vehicle){
            for(ParkingSpot* spot : parkingSpots){
                if(!spot->isAvailable() && spot->getParkedVehicle() == vehicle){
                    spot->unParkVehicle(vehicle);
                    return true;
                }
            }
            return false;
        }

        void displayAvailability(){
            cout<<"Level " <<floorNo<<" availability:"<<'\n';
            for(ParkingSpot* spot : parkingSpots){
                cout<<"Parking Spot: "<<spot->getSpotNumber()<<" "<<(spot->isAvailable() ? "Available" : "Occupied")<<'\n';
            }
        }
};
