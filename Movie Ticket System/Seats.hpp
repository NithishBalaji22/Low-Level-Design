#pragma once
#include<iostream>
#include "SeatStatus.hpp"
using namespace std;

enum SeatType{
    NORMAL,
    PREMIUM
};

class Seats{
    private:
        string seatId;
        int row;
        int cols;
        int price;
        SeatType seatType;
        SeatStatus seatStatus;

    public:
        Seats(string seatId, int row, int cols, int price){
            this->seatId = seatId;
            this->price = price;
            this->row = row;
            this->cols = cols;
            seatStatus = SeatStatus::AVAILABLE;
        }

        void setStatus(SeatStatus status){
            seatStatus = status;
        }

        string getSeatId(){
            return seatId;
        }

        int getPrice(){
            return price;
        }

        int getRow(){
            return row;
        }

        int getCols(){
            return cols;
        }

        SeatType getSeatType(){
            return seatType;
        }

        SeatStatus getSeatStatus(){
            return seatStatus;
        }
};