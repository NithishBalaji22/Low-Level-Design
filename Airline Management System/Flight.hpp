#pragma once
#include <bits/stdc++.h>
#include "Seat.hpp"
#include "SeatType.hpp"
#include "SeatAvailability.hpp"
#include "BookedTickets.hpp"
#define ROWS 3
#define COLS 6
using namespace std;

class Flight{
    private:
        int id;
        vector<vector<Seat*>> seats;
        vector<BookedTicket*> bookedTickets;
    
    public:
        Flight(int id);
        int getId();
        void addBookedTicket(BookedTicket *ticket);
        void initializeSeats();
        bool areSeatsAvailable(int numSeats, SeatType type);
        vector<int> bookSeats(int numSeats, SeatType type);
        void markSeatsAsAvailable(vector<int> seats_);
        void printSummary();
};