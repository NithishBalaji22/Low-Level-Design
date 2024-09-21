#pragma once
#include<bits/stdc++.h>
#include "Seat.hpp"
#include "SeatStatus.hpp"
#include "SeatType.hpp"
using namespace std;

class Concert{
    private:
        int id;
        int rows;
        int cols;
        string concertName;
        string artist;
        string venue;
        int numSeats;
        unordered_map<string, Seat*> mapSeats;
        vector<vector<Seat*>> seats;
        static int concertIdGenerator;
        double concertProfit;
    public:
        Concert(string concertName, string artist, string venue, int rows, int cols){
            id = Concert::concertIdGenerator++;
            this->rows = rows;
            this->cols = cols;
            this->concertName = concertName;
            this->artist = artist;
            this->venue = venue;
            concertProfit = 0.0;
            seats = initializeSeats(rows, cols);
        }

        int getId();
        string getConcertName();
        string getArtist();
        string getVenue();
        vector<vector<Seat*>> getConcertSeats(); 
        unordered_map<string, Seat*> getMapSeats();       
        vector<vector<Seat*>> initializeSeats(int rows, int cols);
        void incrementProfit(double amount);
        void decrementProfit(double amount);
        double bookTicket(vector<pair<int, int>> seats);
        vector<Seat*> markSeatsAsOccupied(vector<pair<int, int>> seats);
        void markSeatsAsAvailable(vector<Seat*> seats);


};