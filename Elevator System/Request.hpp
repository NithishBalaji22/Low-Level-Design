#pragma once
#include "bits/stdc++.h"
#include "Directions.hpp"
using namespace std;

class Request{
    private:
        int sourceFloor;
        int destinationFloor;

    public:
        Request(int sourceFloor, int destinationFloor){
            this->sourceFloor = sourceFloor;
            this->destinationFloor = destinationFloor;
        }

        int getSourceFloor();
        int getdestinationFloor();
};