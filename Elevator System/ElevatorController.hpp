#pragma once
#include <iostream>
#include <vector>
#include "Elevator.hpp"
#include "Request.hpp"

class ElevatorController{
    private:
        static ElevatorController* instance;
        vector<Elevator*> elevatorList;
        ElevatorController(){
            elevatorList = vector<Elevator*>();
        }

    public:
        static ElevatorController* getInstance();
        void addElevator(Elevator* elevator);
        void request(Request* request);
        Elevator* findOptimalElevator(int userLocation);        
};