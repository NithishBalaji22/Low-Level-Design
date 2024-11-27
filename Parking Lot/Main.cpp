#include <iostream>
#include "Account.hpp"
#include "Levels.hpp"
#include "ParkingLotSystem.hpp"
#include "ParkingTicket.hpp"
#include "Vehicle.hpp"
#include "VehicleType.hpp"
using namespace std;

int main(){
    ParkingLot* parkingLot = ParkingLot::getInstance();

    Account* account = new Account(101, 2812, 10000);
    Vehicle* vehicle = new Vehicle("TN59CB9015", VehicleType::MOTORBIKE);

    Level* level1 = new Level(1, 10);
    Level* level2 = new Level(2, 20);

    parkingLot->addLevel(level1);
    parkingLot->addLevel(level2);

    ParkingTicket* ticket = parkingLot->parkvehicle(vehicle);
    this_thread::sleep_for(chrono::seconds(60));
    parkingLot->displayAvailability();

    parkingLot->unparkVehicle(ticket, account);
    parkingLot->displayAvailability();
    cout<<account->getBalance()<<endl;
}