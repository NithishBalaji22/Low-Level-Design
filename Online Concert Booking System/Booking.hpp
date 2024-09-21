#pragma once
#include<iostream>
#include <vector>
#include "BookingStatus.hpp"
#include "User.hpp"
#include "Seat.hpp"
#include "Concert.hpp"
using namespace std;

class Seat;
class Booking{
    private:
        string BOOOKING_ID = "BKG";
        string id;
        User* user;
        Concert* concert;
        vector<Seat*> seats;
        double totalPrice;
        BookingStatus status;

    public:
        Booking(User* user, Concert* concert, vector<Seat*>seats){
            id = generateBookingId(user, concert);
            this->user = user;
            this->concert = concert;
            this->seats = seats;
            status = BookingStatus::PENDING;
        }

        string getId(){
            return id;
        }
        
        User* getUser(){
            return user;
        }

        Concert* getConcert(){
            return concert;
        }

        vector<Seat*> getUserSeats(){
            return seats;
        }

        BookingStatus getBookingStatus(){
            return status;
        }

        void setBookingStatus(BookingStatus status){
            this->status = status;
        }   

        string generateBookingId(User* user, Concert* concert){
            return BOOOKING_ID + concert->getConcertName() + to_string(user->getId());
        }         
};