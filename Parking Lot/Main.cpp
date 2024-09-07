#include "ParkingLotSystem.hpp"
#include "Floor.hpp"
#include "ParkingSpot.hpp"
#include "Vehicle.hpp"
#include "VehicleType.hpp"
#include<bits/stdc++.h>
using namespace std;

int main(){
    ParkingLotSystem* parkingLotSystem = ParkingLotSystem::getInstance();

    parkingLotSystem->addFloors(new Floor(0, 10));
    parkingLotSystem->addFloors(new Floor(1, 20));

    Vehicle* vehicle1 = new Vehicle("TN59CB9015", VehicleType::MOTORBIKE);
    Vehicle* vehicle2 = new Vehicle("TN59NB2812", VehicleType::CAR);

    parkingLotSystem->parkVehicle(vehicle1);
    parkingLotSystem->parkVehicle(vehicle2);

    parkingLotSystem->displayAvailability();

    parkingLotSystem->unParkVehicle(vehicle2);

    parkingLotSystem->displayAvailability();    
}