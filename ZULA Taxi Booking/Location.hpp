#pragma once
#include <iostream>
using namespace std;

class Location{
    private:
        int id;
        string name;
        int distanceFromTheOrgin;
    
    public:
        Location(int id, string name, int distanceFromTheOrgin){
            this->id = id;
            this->name = name;
            this->distanceFromTheOrgin = distanceFromTheOrgin;
        }

        int getId(){
            return id;
        }

        string getLocationName(){
            return name;
        }

        int getDistanceFromTheOrgin(){
            return distanceFromTheOrgin;
        }
};