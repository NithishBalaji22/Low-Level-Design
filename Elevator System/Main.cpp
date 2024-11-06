#include <iostream>
using namespace std;
#include "Elevator.hpp"
#include "Request.hpp"
#include "Direction.hpp"
#include "ElevatorController.hpp"

int main(){
    ElevatorController* controller = ElevatorController::getInstance();
    Elevator* elevator1 = new Elevator(1, 0, 1, Direction::UP);
    Elevator* elevator2 = new Elevator(2, 3, 6, Direction::UP);
    controller->addElevator(elevator1);
    controller->addElevator(elevator2);
    controller->request(new Request(3, 5));
}