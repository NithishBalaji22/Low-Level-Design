#pragma once
#include<iostream>
#include"Car.hpp"
using namespace std;

class Customer;
class Reservation{
    private:
        string id;
        Customer* customer;
        Car* car;
        string RESERVATION_PREFIX = "RESERVE";
        int startDate;
        int endDate;
        int totalAmount;

    public: 
        Reservation(Customer* customer, Car* car, int startDate, int endDate, int amount){
            this->id = generateId(car, startDate, endDate);
            this->customer = customer;
            this->car = car;
            this->startDate = startDate;
            this->endDate = endDate;
            totalAmount = amount;
        }

        string getId(){
            return id;
        }

        Customer* getCustomer(){
            return customer;
        }

        Car* getCar(){
            return car;
        }

        int getAmount(){
            return totalAmount;
        }

        int getStartDate(){
            return startDate;
        }

        int getEndDate(){
            return endDate;
        }

        string generateId(Car* car, int start, int end){
            return RESERVATION_PREFIX + to_string(car->getId()) + (char) start + (char) end;
        }
};