#pragma once
#include<iostream>
using namespace std;

class Passenger{
    private:
        int id;
        string name;
        string emailId;
        string phoneNumber;
        char location;
    
    public:
        Passenger(int id, string name, string emailId, string phoneNumber, char location){
            this->id = id;
            this->name = name;
            this->emailId = emailId;
            this->phoneNumber = phoneNumber;
            this->location = location;
        }

        int getId(){
            return id;
        }

        string getName(){
            return name;
        }

        char getLocation(){
            return location;
        }

        void setLocation(char location){
            this->location = location;
        }
};