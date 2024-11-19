#pragma once
#include <iostream>
using namespace std;

class Vehicle{
    public:
        virtual void createVehicle() = 0;
};

class Bike : public Vehicle{
    public:
        Bike() {}
        void createVehicle() override{
            cout<<"Creating Bike"<<endl;
        }
};

class Car : public Vehicle{
    public:
        Car(){}
        void createVehicle() override{
            cout<<"Creating Car"<<endl;
        }
};

class Truck : public Vehicle{
    public:
        Truck(){}
        void createVehicle() override{
            cout<<"Creating Truck"<<endl;
        }
};