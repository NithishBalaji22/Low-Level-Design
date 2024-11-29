#pragma once
#include <iostream>
#include <vector>
#include "SeatType.hpp"
#include "BookingStatus.hpp"
using namespace std;

class BookedTicket{
    private:
        int id;
        int flightNo;
        SeatType type;
        char mealRequired;
        int totalCost;
        vector<int> seatNo;
        BookingStatus status;

    public:
        BookedTicket(int id, int flightNo, SeatType type, char mealRequired, int totalCost, vector<int> seatNo){
            this->id = id;
            this->flightNo = flightNo;
            this->type = type;
            this->mealRequired = mealRequired;
            this->totalCost = totalCost;
            this->seatNo = seatNo;
            status = BookingStatus::B;

        }

        int getId(){
            return id;
        }

        int getFlightNo(){
            return flightNo;
        }

        SeatType getSeatType(){
            return type;
        }

        BookingStatus getBookingStatus(){
            return status;
        }

        void cancelBooking(){
            status = BookingStatus::C;
        }

        vector<int> getSeatNos(){
            return seatNo;
        }

        char getMealRequired(){
            return mealRequired;
        }

        int getTotalCost(){
            return totalCost;
        }
};