#pragma once
#include <iostream>
using namespace std;

class Customer;
class Cab;
class CabDriver;
class Ride{
    private:
        int id;
        string source;
        string destination;
        Customer* customer;
        Cab* cab;
        int totalFair;
        int ZulaCommission;

    public:
        Ride(int id, string source, string destination, Customer* customer, Cab* cab, int totalFair, int ZulaCommission){
            this->id = id;
            this->source = source;
            this->destination = destination;
            this->customer = customer;
            this->cab = cab;
            this->totalFair = totalFair;
            this->ZulaCommission = ZulaCommission;
        }

        int getRideId(){
            return id;
        }

        string getSource(){
            return source;
        }

        string getDestination(){
            return destination;
        }

        Customer* getCustomer(){
            return customer;
        }

        Cab* getCab(){
            return cab;
        }

        int getTotalFair(){
            return totalFair;
        }

        int getZulaCommission(){
            return ZulaCommission;
        }
};