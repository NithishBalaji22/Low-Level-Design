#pragma once
#include "Directions.hpp"
#include "Request.hpp"
#include "bits/stdc++.h"
using namespace std;

class Elevator{
    private:
        int id;
        int capacity;
        int currentFloor;
        Directions direction;
        queue<Request>requests;
        void processRequest(Request& r);

    public:
        Elevator() {}
        Elevator(int id, int capacity){
            this->id= id;
            this->capacity = capacity;
            currentFloor = 0;
            direction = Directions::UP;
            requests = queue<Request>();
        }

        void processRequest();
        void addRequest(Request r);
        void run();
        int getCurrentFloor();
        int getId();        
};