#pragma once
#include<iostream>
#include "RideStatus.hpp"
using namespace std;

class Driver;
class Passenger;

class Ride{
    private:
        int id;
        Passenger* passenger;
        Driver* driver;
        char sourceLocation;
        char destinationLocation;
        double totalFair;
        RideStatus status;

    public:
        Ride(int id, Passenger* passenger, Driver* driver, char source, char destination, RideStatus status){
            this->id = id;
            this->passenger = passenger;
            this->driver = driver;
            sourceLocation = source;
            destinationLocation = destination;
            this->status = status;
            totalFair = 0;
        }

        //Setter Functions
        void setStatus(RideStatus status){
            this->status = status;
        }

        void setDriver(Driver* driver){
            this->driver = driver;
        }

        void setFair(double fair){
            totalFair = fair;
        }

        //Getter Functions
        int getId(){
            return id;
        }

        Passenger* getPassenger(){
            return passenger;
        }

        Driver* getdriver(){
            return driver;
        }

        char getSource(){
            return sourceLocation;
        }

        char getDestination(){
            return destinationLocation;
        }

        RideStatus getRideStatus(){
            return status;
        }

};