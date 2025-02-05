#include<iostream>
#include "ParkingLotSystem.hpp"
#include "Vehicle.hpp"
#include "VehicleType.hpp"
using namespace std;

int main(){
    ParkingLotSystem* ParkingLot = ParkingLotSystem::getInstance();

    //Creating Vehicle
    Vehicle* bike = new Vehicle("TN59CB9015", VehicleType::MOTORBIKE);
    Vehicle* car = new Vehicle("TN59NB2812", VehicleType::CAR);
    Vehicle* truck = new Vehicle("TN59MN5518", VehicleType::TRUCK);

    //Creating Levels
    cout<<"Hi"<<endl;
    ParkingLot->addLevels(1, 50);

    //Before Parking the Bike
    ParkingLot->displayAvailability();

    //Parking Bike
    ParkingLot->parkVehicle(bike);

    //After Parking the Bike
    ParkingLot->displayAvailability();
}
