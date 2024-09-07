// #include "ElevatorController.hpp"
// #include "bits/stdc++.h"
// using namespace std;

// void ElevatorController::requestElevator(int sourceFloor, int destinationFloor){
//     Elevator optimalElevator = findOptimalElevator(sourceFloor, destinationFloor);
//     optimalElevator.addRequest(Request(sourceFloor, destinationFloor));
// }

// Elevator ElevatorController:: findOptimalElevator(int sourceFloor, int destinationFloor){
//     Elevator optimal;
//     int MIN= INT_MAX;
//     for(Elevator elevator : elevatorList){
//         int distance= abs(destinationFloor - sourceFloor);
//         if(distance < MIN){
//             optimal = elevator;
//             MIN = distance;
//         }
//     }

//     return optimal;
// }

#include "ElevatorController.hpp"
#include "bits/stdc++.h"
using namespace std;

void ElevatorController::requestElevator(int sourceFloor, int destinationFloor) {
    Elevator& optimalElevator = findOptimalElevator(sourceFloor, destinationFloor);
    optimalElevator.addRequest(Request(sourceFloor, destinationFloor));
    optimalElevator.run();
}

Elevator& ElevatorController::findOptimalElevator(int sourceFloor, int destinationFloor) {
    Elevator* optimal = nullptr;
    int MIN = INT_MAX;
    for(Elevator& elevator : elevatorList) {
        int distance = abs(destinationFloor - sourceFloor);
        if(distance < MIN) {
            optimal = &elevator;
            MIN = distance;
        }
    }

    return *optimal;
}

