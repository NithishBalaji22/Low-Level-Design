#pragma once
#include<iostream>
#include "SeatStatus.hpp"
#include "SeatType.hpp"
using namespace std;

class Seat{
    private:
        string id;
        SeatType type;
        SeatStatus status;
        double price;

    public:
        Seat(string id, SeatType type, SeatStatus status, double price){
            this->id = id;
            this->type = type;
            this->status = status;
            this->price = price;
        }

        string getId(){
            return id;
        }

        SeatType getSeatType(){
            return type;
        }

        SeatStatus getSeatStatus(){
            return status;
        }

        double getPrice(){
            return price;
        }

        void setSeatStatus(SeatStatus status){
            this->status = status;
        }
};