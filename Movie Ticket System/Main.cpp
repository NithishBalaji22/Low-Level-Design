#include <bits/stdc++.h>
using namespace std;

#include "TicketBookingSystem.hpp"
#include "Movies.hpp"
#include "User.hpp"
#include "Theater.hpp"
#include "Show.hpp"
#include "Seats.hpp"
#include "Booking.hpp"
#include"SeatStatus.hpp"


unordered_map<string, Seats*> createSeats(int rows, int cols){
    unordered_map<string, Seats*> seats;
    for(int row= 1; row <= rows; row++){
        for(int col= 1; col <= cols; col++){
            string seatId = to_string(row) + '-' + to_string(col);
            SeatType seatType = (row <= 2) ? SeatType::PREMIUM : SeatType::NORMAL;
            int price = (seatType == SeatType::PREMIUM) ? 150 : 120;
            Seats* seat = new Seats(seatId, row, col, price);
            seats.insert({seatId, seat});
        }
    }        
    return seats;
}
int main(){
    TicketBookingSystem* ticketBookingSystem = TicketBookingSystem::getInstance();

    Movies* movie1 = new Movies(1, "GOAT", "ACTION, THRILLER, SUSPENCE", Ratings::FIVE_STAR, 180);
    Movies* movie2 = new Movies(2, "BAHUBALI", "HISTORY", Ratings::FOUR_STAR, 170);

    ticketBookingSystem->addMovies(movie1);
    ticketBookingSystem->addMovies(movie2);

    Theater* theater1 = new Theater(1, "RADIANCE", "MADURAI", vector<Shows*>());
    Theater* theater2 = new Theater(2, "INOX", "MADURAI", vector<Shows*>());

    ticketBookingSystem->addTheater(theater1);
    ticketBookingSystem->addTheater(theater2);

    Shows* show1 = new Shows(1, "MADURAI", theater1, movie1, createSeats(10,10));
    Shows* show2 = new Shows(2, "CHENNAI", theater2, movie2, createSeats(5,5));

    ticketBookingSystem->addShow(show1);
    ticketBookingSystem->addShow(show2);

    User* user = new User(1, "NITHISH", "digitalnithish2003@gamil.com", "8754685518");
    vector<Seats*> seats = {show1->getSeats().at("1-5"), show1->getSeats().at("1-6")};
    Booking* booking= ticketBookingSystem->bookTicket(user, show1, seats);    
    if(booking != nullptr){
        ticketBookingSystem->markSeatsAsBooked(show1, seats);
        cout<<"Booking has been Successfully processed for the movie: "<<booking->getBookingId()<<'\n';
    }else{
        cout<<"Sorry the booking has not been done due to some techinical issue"<<'\n';
    }

    //Cancelling
    string bookingId;
    cout<<"Enter your Booking Id the Booking id will be BKG follows by your name 3 characters: ";
    cin>>bookingId;

    if(ticketBookingSystem->cancelBooking(bookingId)){
        cout<<"Booking has been cancelled succesfully"<<'\n';
    }else{
        cout<<"Please enter valid Booking id and then try again"<<'\n';
    }
}