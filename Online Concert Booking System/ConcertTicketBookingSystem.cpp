#include "ConcertTicketBookingSystem.hpp"

ConcertTicketBookingSystem* ConcertTicketBookingSystem::instance = nullptr;

ConcertTicketBookingSystem* ConcertTicketBookingSystem::getInstance(){
    if(instance == nullptr){
        instance = new ConcertTicketBookingSystem();
    }
    return instance;
}

void ConcertTicketBookingSystem::registerUser(User* user){
    users[user->getId()] = user;
}

void ConcertTicketBookingSystem::registerConcert(Concert* concert){
    concerts[concert->getId()] = concert;
}

void ConcertTicketBookingSystem::addBooking(Booking* booking){
    bookings[booking->getId()] = booking;
}

void ConcertTicketBookingSystem::bookTicket(User* user, Concert* concert, vector<pair<int, int>> seats){
    double totalAmount = concert->bookTicket(seats);
    bool status = processPayment(user, totalAmount);
    if(status){
        vector<Seat*> bookedSeats = concert->markSeatsAsOccupied(seats);
        concert->incrementProfit(totalAmount);
        Booking* booking = new Booking(user, concert, bookedSeats);
        booking->setBookingStatus(BookingStatus::CONFIRMED);  // Update status
        bookings[booking->getId()] = booking;
        cout<<"Your Booking for the Concert: "<<concert->getConcertName()<<" is Successfull and Your Booking Id is: "<<booking->getId();
        return;
    }
    cout<<"Insufficient Funds!"<<'\n';
}

void ConcertTicketBookingSystem::cancelTicket(string bookingId){
    auto it = bookings.find(bookingId);
    if (it != bookings.end()) {
        Booking* booking = it->second;
        User* user = booking->getUser();
        Concert* concert = booking->getConcert();
        vector<Seat*> seats = booking->getUserSeats();
        concert->markSeatsAsAvailable(seats);
        booking->setBookingStatus(BookingStatus::CANCELLED);
    }else {
        cout << "Booking ID not found!" << endl;
    }
}

bool ConcertTicketBookingSystem::processPayment(User* user, double amount){
    double balance = user->getBalance();
    if(balance - amount >= 0){
        user->debitAmount(amount);
        return true;
    }
    return false;
}

