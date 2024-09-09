#pragma once
#include<iostream>
using namespace std;

class MenuItem{
    private:
        string id;
        string name;
        string description;
        double price;
        bool isAvailable;

    public:
        MenuItem(string id, string name, string description, double price, bool status){
            this->id = id;
            this->name = name;
            this->description = description;
            this->price = price;
            isAvailable = status;
        }

        string getMenuItemId(){
            return id;
        }

        string getItemName(){
            return name;
        }

        bool getMenuItemAvailability(){
            return isAvailable;
        }

        void setMenuItemAvailability(bool status){
            isAvailable = status;
        }
};