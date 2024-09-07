#pragma once
#include<bits/stdc++.h>
using namespace std;

enum BookingStatus{
    BOOKED,
    PENDING,
    CANCELLED,
    CONFIRMED
};

class User;
class Shows;
class Seats;

class Booking{
    private:
        string bookingId;
        BookingStatus status;
        User* user;
        Shows* shows;
        vector<Seats*>seats;

    public:
        Booking(string bookingId, User* user, Shows* shows, BookingStatus status, vector<Seats*>seats){
            this->bookingId = bookingId;
            this->user = user;
            this->shows = shows;
            this->status = status;
            this->seats = seats;
        }

        void setBookingStatus(BookingStatus status){
            this->status = status;            
        }
        
        string getBookingId(){
            return bookingId;
        }

        User* getUser(){
            return user;
        }

        Shows* getShow(){
            return shows;
        }

        vector<Seats*> getSeats(){
            return seats;
        }

        BookingStatus getBookingStatus(){
            return status;
        }
};