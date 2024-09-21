#include<bits/stdc++.h>
#include "ConcertTicketBookingSystem.hpp"
#include "User.hpp"
#include "Concert.hpp"
using namespace std;

void displaySeatAvailability(Concert* concert) {
    cout<< "\nSeat Availability for Concert: " << concert->getConcertName() << endl;
    cout<< "----------------------------------------" << endl;
    vector<vector<Seat*>> seats = concert->getConcertSeats();
    unordered_map<string, Seat*> mapSeats = concert->getMapSeats();
    for(int row = 1; row <= seats.size(); row++) {
        for(int col = 1; col <= seats[0].size(); col++) {
            string seatId = to_string(row) + '-' + to_string(col);
            Seat* seat = mapSeats.at(seatId);
            if(seat->getSeatStatus() == SeatStatus::AVAILABLE) cout << "A "; 
            else cout << "O "; 
        }
        cout << endl;
    }
    cout << "A: Available, O: Occupied" << endl;
    cout << "----------------------------------------\n" << endl;
}

int main(){
    ConcertTicketBookingSystem* system = ConcertTicketBookingSystem::getInstance();

    cout << "Registering Users" << endl;
    User* user1 = new User("Nithish", "nithish@gamil.com", "1234567890", 10000, "Madurai");
    system->registerUser(user1);
    cout << "User Registered: " << user1->getName() << " (ID: " << user1->getId() << ")" << endl;

    User* user2 = new User("Sri Ganesh", "mani@gmail.com", "987654321", 8000, "Chennai");
    system->registerUser(user2);
    cout << "User Registered: " << user2->getName() << " (ID: " << user2->getId() << ")" << endl;

    cout << "\nRegistering Concert" << endl;
    Concert* concert1 = new Concert("Thana Sentha Kootam", "Anirudh", "Medavakam", 5, 5);
    system->registerConcert(concert1);
    cout << "Concert Registered: " << concert1->getConcertName() << " (ID: " << concert1->getId() << ")" << endl;

    cout << "\nBooking Tickets for " << user1->getName() << endl;
    displaySeatAvailability(concert1);

    int numSeats1;
    cout << "Enter number of seats to book for " << user1->getName() << ": ";
    cin >> numSeats1;
    vector<pair<int, int>> seatsToBook1;
    for(int i = 0; i < numSeats1; ++i){
        int row, col;
        cout << "Enter seat " << i+1 << " row and column (e.g., 1 2): ";
        cin >> row >> col;
        seatsToBook1.emplace_back(make_pair(row, col));
    }
    system->bookTicket(user1, concert1, seatsToBook1);

    cout << "\nBooking Tickets for " << user2->getName() << endl;
    displaySeatAvailability(concert1);

    int numSeats2;
    cout << "Enter number of seats to book for " << user2->getName() << ": ";
    cin >> numSeats2;
    vector<pair<int, int>> seatsToBook2;
    for(int i = 0; i < numSeats2; ++i){
        int row, col;
        cout << "Enter seat " << i+1 << " row and column (e.g., 3 4): ";
        cin >> row >> col;
        seatsToBook2.emplace_back(make_pair(row, col));
    }
    system->bookTicket(user2, concert1, seatsToBook2);

    // Display Seat Availability after Bookings
    cout << "\nSeat Availability after Bookings:" << endl;
    displaySeatAvailability(concert1);

    // Cancel Booking for User1
    cout << "\nCanceling Booking for " << user1->getName() << "..." << endl;
    string bookingIdToCancel;
    cout << "Enter Booking ID to cancel: ";
    cin >> bookingIdToCancel;
    system->cancelTicket(bookingIdToCancel);
    cout << "Booking " << bookingIdToCancel << " has been canceled." << endl;

    // Display Seat Availability after Cancellation
    cout << "\nSeat Availability after Cancellation:" << endl;
    displaySeatAvailability(concert1);
    
    return 0;
}
