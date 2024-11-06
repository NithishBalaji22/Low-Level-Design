#include "Directions.hpp"
#include "Elevator.hpp"
#include "ElevatorController.hpp"
#include "bits/stdc++.h"
using namespace std;

int main(){
    ElevatorController controller(3,5);
    controller.requestElevator(3,7);
    controller.requestElevator(8,2);
    controller.requestElevator(1,9);
}