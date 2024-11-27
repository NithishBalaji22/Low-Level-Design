#include "ParkingLotSystem.hpp"

ParkingLot* ParkingLot::instance = nullptr;
int ParkingLot::paymentId = 1;

ParkingLot* ParkingLot::getInstance(){
    if(instance == nullptr){
        instance = new ParkingLot();
    }
    return instance;
}

void ParkingLot::addLevel(Level* level){
    levels.emplace_back(level);
}

ParkingTicket* ParkingLot::parkvehicle(Vehicle* vehicle){
    for(auto level : levels){
        if(level->parkVehicle(vehicle)){
            ParkingTicket* parkingTicket = new ParkingTicket(chrono::high_resolution_clock::now(), vehicle);
            return parkingTicket;
        }
    }
    return nullptr;
}

void ParkingLot::unparkVehicle(ParkingTicket* ticket, Account* account){
    int bikeMinuteCharge = 10;
    int carMinuteCharge = 20;
    int truckMinuteCharge = 30;

    Vehicle* vehicle = ticket->getVehicle();
    VehicleType type = vehicle->getVehicleType();
    auto start = ticket->getStartTime();
    auto end = chrono::high_resolution_clock::now();
    for(auto level : levels){
        if(level->unParkVehicle(vehicle)){
            auto duration = chrono::duration_cast<chrono::seconds>(end - start);
            int seconds = duration.count();
            int minutes = seconds / 60;
            int amount = minutes * (vehicle->getVehicleType() == VehicleType::MOTORBIKE ? bikeMinuteCharge : (vehicle->getVehicleType() == VehicleType::CAR ? carMinuteCharge : truckMinuteCharge));
            if(amount > account->getBalance()){
                cout<<"Insufficient Funds !!"<<endl;
                return;
            }
            PaymentFlowInterface* payment = new PaymentFlow(generatePaymentId(), account, amount);
            payment->execute();            
        }
    }
}

void ParkingLot::displayAvailability(){
    cout<<"Displaying the availability:"<<endl;
    for(auto level : levels){
        level->displayAvailability();
    }
}

int ParkingLot::generatePaymentId(){
    return paymentId++;
}
