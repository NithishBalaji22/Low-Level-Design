#include "TicketBookingSystem.hpp"

TicketBookingSystem* TicketBookingSystem::instance = nullptr;

TicketBookingSystem* TicketBookingSystem::getInstance(){
    //Singleton Design Pattern
    if (instance == nullptr){
        instance = new TicketBookingSystem();
    }
    return instance;
}

void TicketBookingSystem::addUsers(User* user){
    users.emplace_back(user);
}

void TicketBookingSystem::addTheater(Theater* theater){
    theaters.emplace_back(theater);
}

void TicketBookingSystem::addMovies(Movies* movie){
    movies.emplace_back(movie);
}

void TicketBookingSystem::addShow(Shows* show){
    shows.emplace_back(show);
}

void TicketBookingSystem::addBooking(string id, Booking* booking){
    bookings[id] = booking;
}

Booking* TicketBookingSystem::bookTicket(User* user, Shows* show, vector<Seats*>seats){
    if(areSeatsAvailable(show, seats)){
        markSeatsAsBooked(show, seats);
        int totalPrice = calTotalPrice(seats);
        string userName = user->getName();
        // string bookingId = generateBookingId(User* user);
        string bookingId = generateBookingId(userName);
        Booking* booking = new Booking(bookingId, user, show, BookingStatus::PENDING,  seats);
        bookings[bookingId] = booking;
        return booking;
    }else{
        cout<<"Seats Are Not Available Sorry !"<<'\n';
        return nullptr;
    }
}

string TicketBookingSystem::generateBookingId(string userName){
    return BOOKING_ID_PREFIX + userName[0] + userName[1] + userName[2]; 
}

bool TicketBookingSystem::areSeatsAvailable(Shows* show, vector<Seats*>seats){
    for(Seats* seat : seats){
        Seats* showSeat = show->getSeats().at(seat->getSeatId());
        if(showSeat == nullptr || showSeat->getSeatStatus() != SeatStatus::AVAILABLE){
            return false;
        }
    }
    return true;
}

bool TicketBookingSystem::confirmBooking(string bookingId){
    Booking* booking = bookings[bookingId];
    if(booking != nullptr){
        booking->setBookingStatus(BookingStatus::CONFIRMED);
        return true;
    }

    return false;
}

bool TicketBookingSystem::cancelBooking(string bookingId){
    Booking* booking= bookings[bookingId];
    if(booking != nullptr && booking->getBookingStatus() != BookingStatus::CANCELLED){
        booking->setBookingStatus(BookingStatus::CANCELLED);
        markSeatsAsAvailable(booking->getShow(), booking->getSeats());
        return true;
    }
    return false;
}

void TicketBookingSystem::markSeatsAsAvailable(Shows* show, vector<Seats*>seats){
    for(Seats* seat : seats){
        Seats* showSeats = show->getSeats().at(seat->getSeatId());
        if(showSeats->getSeatStatus() == SeatStatus::BOOKEDD){
            showSeats->setStatus(SeatStatus::AVAILABLE);
        }
    }        
}

void TicketBookingSystem::markSeatsAsBooked(Shows* show, vector<Seats*>seats){
    for(Seats* seat : seats){
        Seats* showSeat = show->getSeats().at(seat->getSeatId());
        showSeat->setStatus(SeatStatus::BOOKEDD);
    }
}

int TicketBookingSystem::calTotalPrice(vector<Seats*>seat){
    int total= 0;
    for(Seats* s : seat){
        total += s->getPrice();
    }

    return total;
}

