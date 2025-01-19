#include "VehicleFactory.hpp"
#include "Vehicle.hpp"
#include <iostream>
using namespace std;

int main(){
    Vehicle* vehicle = VehicleFactory::getVehicle("Car");
    vehicle->createVehicle();
}