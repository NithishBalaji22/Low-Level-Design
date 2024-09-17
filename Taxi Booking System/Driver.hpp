#pragma once
#include<iostream>
#include "DriverStatus.hpp"
using namespace std;

class Driver{
    private:
        int id;
        string name;
        string emailId;
        string phoneNumber;
        int totalEarnings;
        char currentLocation;
        DriverStatus status;

    public:
        Driver(int id, string name, string emailId, string phoneNumber){
            this->id = id;
            this->name = name;
            this->emailId = emailId;
            this->phoneNumber = phoneNumber;
            totalEarnings = 0;
            currentLocation = 'A';
            status = DriverStatus::AVAILABLE;
        }

        //Setter Functions
        void setDriverEarnings(int earning){
            totalEarnings += earning;
        }

        void setDriverStatus(DriverStatus status){
            this->status = status;
        }

        void setLocation(char location){
            currentLocation = location;
        }

        //Getter Functions
        int getId(){
            return id;
        }

        string getName(){
            return name;
        }

        int getTotalEarnings(){
            return totalEarnings;
        }

        DriverStatus getDriverStatus(){
            return status;
        }

        char getDriverLocation(){
            return currentLocation;
        }
};