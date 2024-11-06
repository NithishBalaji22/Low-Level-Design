#include "ElevatorController.hpp"

ElevatorController* ElevatorController::instance = nullptr;
ElevatorController* ElevatorController::getInstance(){
    if(instance == nullptr){
        instance = new ElevatorController();
    }
    return instance;
}

void ElevatorController::addElevator(Elevator* elevator){
    elevatorList.emplace_back(elevator);
}

void ElevatorController::request(Request* request){
    int source = request->getSource();
    Elevator* elevator = findOptimalElevator(source);
    if(elevator != nullptr){
        elevator->addRequest(request);
        elevator->run();
    }else{
        cout<<"We could fullfill your request!!";
        exit(0);
    }
}

Elevator* ElevatorController::findOptimalElevator(int source){
    int _Min = INT_MAX;
    Elevator* optimalElevator = nullptr;
    for(auto elevator : elevatorList){
        int distance = abs(elevator->getCurrentFloor() - source);
        if(distance <= _Min){
            optimalElevator = elevator;
            _Min = abs(elevator->getCurrentFloor() - source);
        }
    }

    return optimalElevator;
}