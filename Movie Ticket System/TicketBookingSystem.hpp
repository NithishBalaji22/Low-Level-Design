#pragma once
#include<bits/stdc++.h>
using namespace std;

#include "User.hpp"
#include "Theater.hpp"
#include "Movies.hpp"
#include "Show.hpp"
#include "Booking.hpp"
#include "Seats.hpp"
#include"SeatStatus.hpp"

class TicketBookingSystem{
    private:
        string BOOKING_ID_PREFIX = "BKG";
        vector<User*> users;
        vector<Theater*> theaters;
        vector<Movies*> movies;
        vector<Shows*> shows;
        unordered_map<string, Booking*> bookings; 
        TicketBookingSystem(){
            users = vector<User*>();
            theaters = vector<Theater*>();
            movies = vector<Movies*>();
            shows = vector<Shows*>();
            bookings = unordered_map<string, Booking*>();
        }
        static TicketBookingSystem* instance;

    public:
        static TicketBookingSystem* getInstance();
        void addUsers(User* user);
        void addTheater(Theater* theater);
        void addMovies(Movies* movie);
        void addShow(Shows* show);
        void addBooking(string id, Booking* booking);    
        bool areSeatsAvailable(Shows* show, vector<Seats*>seats);  
        void markSeatsAsBooked(Shows* show, vector<Seats*> selectedSeats);
        int calTotalPrice(vector<Seats*> seats);
        bool cancelBooking(string bookingId);
        bool confirmBooking(string bookingId);
        void markSeatsAsAvailable(Shows* show, vector<Seats*>seats);
        Booking* bookTicket(User* user, Shows* show, vector<Seats*>seats);
        string generateBookingId(string userName);
};