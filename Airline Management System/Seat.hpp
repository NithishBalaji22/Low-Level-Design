#pragma once
#include <iostream>
#include "SeatType.hpp"
#include "SeatAvailability.hpp"
using namespace std;

class Seat{
    private:
        int id;
        SeatType type;
        SeatAvailability availability;
    
    public:
        Seat(int id, SeatType type){
            this->id = id;
            this->type = type;
            availability = SeatAvailability::AVAILABLE;
        }

        int getId(){
            return id;
        }

        void seatOccupied(){
            availability = SeatAvailability::OCCUPIED;
        }

        void seatAvailable(){
            availability = SeatAvailability::AVAILABLE;
        }

        SeatAvailability getAvailability(){
            return availability;
        }

        SeatType getSeatType(){
            return type;
        }
};