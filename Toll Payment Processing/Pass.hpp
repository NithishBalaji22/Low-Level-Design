#pragma once
#include <iostream>
using namespace std;

class Car;
class User;
class Toll;
class Pass{
    private:
        int passId;
        User* user;
        Car* car;
        Toll* toll;
        int amount;
    
    public:
        Pass(int passId, User* user, Car* car, Toll* toll, int amount){
            this->passId = passId;
            this->user = user;
            this->car = car;
            this->toll = toll;
            this->amount = amount;
        }

        Toll* getToll(){
            return toll;
        }

        int getAmount(){
            return amount;
        }
};