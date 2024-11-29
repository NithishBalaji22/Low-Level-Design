#pragma once
#include <bits/stdc++.h>
#include "BookedTickets.hpp"
#include "Flight.hpp"
using namespace std;

class AirlineManagementSystem{
    private:
        static int bookingId;
        static int economySeatFair;
        static int businessSeatFair;
        static AirlineManagementSystem* instance;
        unordered_map<int, Flight*> flights;
        map<int, BookedTicket*> bookedTickets;
        AirlineManagementSystem(){
            flights = unordered_map<int, Flight*>();
            bookedTickets = map<int, BookedTicket*>();
        }

    public:
        static AirlineManagementSystem* getInstance();
        void addFlight(Flight* flight);
        void bookTicket();
        void cancelTicket();
        void viewFlightSummary();
        void viewBookingSummary();
};