#pragma once
#include "bits/stdc++.h"
#include "Elevator.hpp"
#include "Request.hpp"
using namespace std;

class ElevatorController{
    private:
        int elevatorCount;
        int capacity;
        vector<Elevator>elevatorList;

    public:
        ElevatorController(int elevatorCount, int capacity){
            elevatorList = vector<Elevator>();
            for(int i=0; i<elevatorCount; i++){
                elevatorList.emplace_back(Elevator(i+1, capacity));
            }
        }

        void requestElevator(int sourceFloor, int destinationFloor);
        //Elevator findOptimalElevator(int source, int destination);
        Elevator& findOptimalElevator(int source, int destination);
};