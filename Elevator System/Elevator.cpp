#include "Elevator.hpp"
#include <bits/stdc++.h>
using namespace std;

int Elevator::getId(){
    return id;
}

int Elevator::getCurrentFloor(){
    return currentFloor;    
}

void Elevator::processRequest(){
    while(!requests.empty()){
        Request r= requests.front();
        requests.pop();
        processRequest(r);
    }    
}

void Elevator::processRequest(Request& r){
    int destinationFloor = r.getdestinationFloor();
    if(currentFloor < destinationFloor){
        direction = Directions::UP;
        for(int i=currentFloor; i<=destinationFloor; i++){
            currentFloor = i;
            cout<<"Current Floor: "<<i<<'\n';
        }
        cout<<"Thank you !"<<'\n';
    }else{
        direction = Directions::DOWN;
        for(int i=currentFloor; i>=destinationFloor; i--){
            currentFloor = i;
            cout<<"Current Floor: "<<i<<'\n';
        }
        cout<<"Thank you !"<<'\n';
    }
}

void Elevator::addRequest(Request r){
    if(requests.size() < capacity){
        requests.push(r);
        cout<<"Request has been added succesfully to the elevator id: "<<getId()<<'\n';
    }
}

void Elevator::run(){
    processRequest();
}
