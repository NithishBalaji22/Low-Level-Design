#include"ParkingLotSystem.hpp"

ParkingLotSystem* ParkingLotSystem::instance = nullptr;

ParkingLotSystem* ParkingLotSystem::getInstance(){
    //Singleton Logic Implementation
    if(instance == nullptr){
        instance = new ParkingLotSystem();
    }
    return instance;
}

void ParkingLotSystem::addFloors(Floor* floor){
    floors.emplace_back(floor);
}

bool ParkingLotSystem::parkVehicle(Vehicle* vehicle){
    for(Floor* floor : floors){
        if(floor->parkVehicle(vehicle)){
            return true;
        }
    }
    return false;
}

bool ParkingLotSystem::unParkVehicle(Vehicle* vehicle){
    for(Floor* floor : floors){
        if(floor->unparkVehicle(vehicle)){
            return true;
        }
    }
    return false;
}

void ParkingLotSystem::displayAvailability(){
    for(Floor* floor : floors){
        floor->displayAvailability();
    }
}
