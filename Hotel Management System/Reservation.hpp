#pragma once
#include<iostream>
#include "ReservationStatus.hpp"
using namespace std;

class Guest;
class Room;
class Hotel;
class Reservation{
    private:
        int id;
        Guest* guest;
        Hotel* hotel;
        Room* room;
        int amount;
        ReservationStatus status;
        int checkInDate;
        int checkOutDate;

    public:
        Reservation(int id, Guest* guest, Hotel* hotel, Room* room, int amount, int checkInDate, int checkOutDate){
            this->id = id;
            this->guest = guest;
            this->hotel = hotel;
            this->room = room;
            this->amount = amount;
            this->checkInDate = checkInDate;
            this->checkOutDate = checkOutDate;
            status = ReservationStatus::CONFIRMED;
        }

        int getReservationId(){
            return id;
        }

        int getAmount(){
            return amount;
        }

        Hotel* getHotel(){
            return hotel;
        }

        Room* getRoom(){
            return room;
        }

        Guest* getGuest(){
            return guest;
        }

        ReservationStatus getReservationStatus(){
            return status;
        }

        void markAsCancelled(){
            status = ReservationStatus::CANCELLED;
        }
};