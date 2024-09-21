#pragma once
#include<bits/stdc++.h>
#include "Concert.hpp"
#include"Seat.hpp"
#include"SeatStatus.hpp"
#include "Booking.hpp"
#include "BookingStatus.hpp"
#include"SeatType.hpp"
#include"user.hpp"
using namespace std;

class ConcertTicketBookingSystem{
    private:
        static ConcertTicketBookingSystem* instance;
        unordered_map<int, User*> users;
        unordered_map<int, Concert*> concerts;
        unordered_map<string, Booking*> bookings;
        ConcertTicketBookingSystem(){
            users = unordered_map<int, User*>();
            concerts = unordered_map<int, Concert*>();
            bookings = unordered_map<string, Booking*>();
        }

    public:
        static ConcertTicketBookingSystem* getInstance();
        void registerUser(User* user);
        void registerConcert(Concert* concert);
        void addBooking(Booking* booking);
        void bookTicket(User* user, Concert* concert, vector<pair<int, int>> seats);
        void cancelTicket(string bookingId);
        bool processPayment(User* user, double amount);

};