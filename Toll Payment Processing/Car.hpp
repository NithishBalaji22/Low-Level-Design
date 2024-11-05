#pragma once
#include <iostream>
#include <vector>
#include "CarType.hpp"
#include "Fuel.hpp"
using namespace std;

class Pass;
class User;
class Car{  
    private:
        string numberPlate;
        string brandName;
        char initalJouneyLocation;
        char finalJouneyLocation;
        char location;
        Fuel fuel;
        CarType type;
        User* user;
        vector<Pass*> passList;
    
    public:
        Car(string numberPlate, string brandName, Fuel fuel, CarType type, char initalJouneyLocation, char finalJouneyLocation, User* user){
            this->numberPlate = numberPlate;
            this->brandName = brandName;
            this->fuel = fuel;
            this->type = type;
            this->user = user;
            this->initalJouneyLocation = initalJouneyLocation;
            this-> finalJouneyLocation = finalJouneyLocation;
            location = initalJouneyLocation;
        }

        string getNumberPlate(){
            return numberPlate;
        }

        User* getUser(){
            return user;
        }

        void addPass(Pass* pass){
            passList.emplace_back(pass);
        }

        vector<Pass*> getPass(){
            return passList;
        }

        char getLocation(){
            return location;
        }

        char getDestinationLocation(){
            return finalJouneyLocation;
        }

        void setLocation(char location){
            this->location = location;
        }

        CarType getCarType(){
            return type;
        }
};