#pragma once
#include <iostream>
#include <vector>
#include "Vehicle.hpp"
#include "VehicleType.hpp"
#include "ParkingSpot.hpp"
using namespace std;

class Level{
    private:
        int levelNo;
        int numSpots;
        vector<ParkingSpot*> parkingSpots;

    public:
        Level(int levelNo, int numSpots){
            this->levelNo = levelNo;
            this->numSpots = numSpots;

            int totalBikeSpots = 0.50 * numSpots;
            int totalCarSpots = 0.40 * numSpots;

            for(int i=1; i<=totalBikeSpots; i++){
                parkingSpots.emplace_back(new ParkingSpot(i, VehicleType::MOTORBIKE));
            }

            for(int i=totalBikeSpots+1; i<=totalBikeSpots+totalCarSpots; i++){
                parkingSpots.emplace_back(new ParkingSpot(i, VehicleType::CAR));
            }

            for(int i=totalBikeSpots+totalCarSpots+1; i<=numSpots; i++){
                parkingSpots.emplace_back(new ParkingSpot(i, VehicleType::TRUCK));
            }
        }

        bool parkVehicle(Vehicle* vehicle){
            for(auto spot : parkingSpots){
                if(spot->isParkingSpotAvailable() && vehicle->getVehicleType() == spot->getSpotType()){
                    spot->parkVehicle(vehicle);
                    return true;
                }
            }
            return false;
        }

        bool unParkVehicle(Vehicle* vehicle){
            for(auto spot : parkingSpots){
                if(!spot->isParkingSpotAvailable() && spot->getVehicle()->getLicensePlate() == vehicle->getLicensePlate()){
                    cout<<"Unparked the Car " <<vehicle->getVehicleType()<< "!!"<<endl;
                    spot->unparkVehicle();
                    return true;
                }
            }
            return false;
        }

        void displayAvailability(){
            cout<<"Level: "<<levelNo<<" Availability"<<endl;
            for(auto spot : parkingSpots){
                if(spot->isParkingSpotAvailable()){
                    cout<<spot->getSpotId()<<" "<<" Available"<<endl;
                }else{
                    cout<<spot->getSpotId()<<" "<<" Occupied"<<endl;
                }
            }
        }
};