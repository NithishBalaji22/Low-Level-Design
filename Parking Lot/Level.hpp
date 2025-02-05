#pragma once
#include <iostream>
#include <vector>
#include "ParkingSpots.hpp"
using namespace std;

class Level{
    private:
        int id;
        vector<ParkingSpots*> spots;

    public:
        Level(int levelNum, int numSpots) {
            int bikeSpots = numSpots * 0.5;
            int carSpots = numSpots * 0.4;
            int truckSpots = numSpots * 0.1;

            for (int i = 1; i <= bikeSpots; i++) {
                spots.push_back(new ParkingSpots(i, VehicleType::MOTORBIKE));
            }

            for (int i = bikeSpots + 1; i <= bikeSpots + carSpots; i++) {
                spots.push_back(new ParkingSpots(i, VehicleType::CAR));
            }

            for (int i = bikeSpots + carSpots + 1; i <= numSpots; i++) {
                spots.push_back(new ParkingSpots(i, VehicleType::TRUCK));
            }
        }


        bool parkVehicle(Vehicle* vehicle){
            for(auto spot : spots){
                if(spot->parkVehicle(vehicle)){
                    return true;
                }
            }
            return false;
        }

        bool unParkVehicle(Vehicle* vehicle){
            for(auto spot : spots){
                if(spot->getVehicle() == vehicle){
                    spot->unParkVehicle();
                    return true;
                }
            }
            return false;
        }

        void displayAvailability(){
            for(auto spot : spots){
                if(spot->isSpotAvailable()){
                    cout<<"Parking Spot is Available on the Spot ID: "<<spot->getSpotId()<<'\t'<<spot->printSpotType()<<'\n';
                }
            }
        }
};