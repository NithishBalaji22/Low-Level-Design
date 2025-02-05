#include "ParkingLotSystem.hpp"

ParkingLotSystem* ParkingLotSystem::instance = nullptr;

ParkingLotSystem* ParkingLotSystem::getInstance(){
    if(instance == nullptr){
        instance = new ParkingLotSystem();
    }
    return instance;
}

void ParkingLotSystem::addLevels(int totalLevels, int spotsPerLevel) {
    for (int i = 0; i < totalLevels; i++) {
        levels.push_back(new Level(i, spotsPerLevel));
    }
}


void ParkingLotSystem::parkVehicle(Vehicle* vehicle){
    for(auto level : levels){
        if(level->parkVehicle(vehicle)){
            cout<<"Vehicle Id: "<<vehicle->getLicensePlate()<<" parked successfully"<<endl;
            return;
        }
    }
    cout<<"Vehicle couldnt be parked"<<endl;
}

void ParkingLotSystem::unParkVehicle(Vehicle* vehicle){
    for(auto level : levels){
        if(level->unParkVehicle(vehicle)){
            cout<<"Vehicle Id: "<<vehicle->getLicensePlate()<<" Unparked successfully"<<endl;
            return;
        }
    }
}

void ParkingLotSystem::displayAvailability(){
    for(auto level : levels){
        level->displayAvailability();
    }
}
