#pragma once
#include <iostream>
using namespace std;

class MenuItem{
    private:
        int id;
        string name;
        int amount;
        bool isAvailable;

    public:
        MenuItem(int id, string name, int amount){
            this->id = id;
            this->name = name;
            this->amount = amount;
            isAvailable = true;
        }

        int getId(){
            return id;
        }

        void markUnavailable(){
            isAvailable = false;
        }

        void markAvailable(){
            isAvailable = true;
        }

        string getName(){
            return name;
        }

        int getAmount(){
            return amount;
        }
};