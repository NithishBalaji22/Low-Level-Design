#pragma once
#include<iostream>
#include "CarType.hpp"
using namespace std;

class Car{
    private:
        int id;
        string brandName;
        string modelName;
        int yearOfMake;
        CarType type;
        bool isAvailable;
        int perDayRentalCost;
    
    public:
        Car(int id, string brandName, string modelName, int makeYear, CarType type, int perDayRentalCost){
            this->id = id;
            this->brandName = brandName;
            this->modelName = modelName;
            yearOfMake = makeYear;
            isAvailable = true;
            this->perDayRentalCost = perDayRentalCost;
        }

        int getId(){
            return id;
        }

        string getBrandName(){
            return brandName;
        }

        string getModelName(){
            return modelName;
        }

        int getYearOfMake(){
            return yearOfMake;
        }

        CarType getCarType(){
            return type;
        }

        bool getAvailability(){
            return isAvailable;
        }

        int getPerDayRentalCost(){
            return perDayRentalCost;
        }

        void setPerDayRentalCost(int cost){
            perDayRentalCost = cost;
        }

        void setAvailability(bool status){
            isAvailable = status;
        }


};