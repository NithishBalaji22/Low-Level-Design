#include "AirlineManagementSystem.hpp"

AirlineManagementSystem* AirlineManagementSystem::instance = nullptr;
int AirlineManagementSystem::bookingId = 1;
int AirlineManagementSystem::economySeatFair = 1000;
int AirlineManagementSystem::businessSeatFair = 2000;

AirlineManagementSystem* AirlineManagementSystem::getInstance(){
    if(instance == nullptr){
        instance = new AirlineManagementSystem();
    }
    return instance;
}

void AirlineManagementSystem::addFlight(Flight* flight){
    // if(flight != nullptr){
    //     flights[flight->getId()] = flight;
    //     cout<<"Flight has been added!"<<endl;
    // }else{
    //     cout<<"Flight has not added"<<endl;
    // }

    flights[flight->getId()] = flight;
}

void AirlineManagementSystem::bookTicket(){
    int flightNo;
    string seat;
    SeatType type;
    int totalSeats;

    cout<<"Enter the flight no: ";
    cin>>flightNo;

    //cout<<"1. Economy\n2. Business\nEnter the type of seat: ";
    cout<<"Enter the type of seat: ";
    cin>>seat;

    if(seat == "Economy") type = SeatType::EC;        
    else type = SeatType::BC;

    cout<<"Enter total number of seats: ";
    cin>>totalSeats;

    // Flight* flight = flights[flightNo];
    auto it = flights.find(flightNo);
    if(it != flights.end()){
        Flight* flight = it->second;
        bool areSeatsAvailable = flight->areSeatsAvailable(totalSeats, type);
        if(areSeatsAvailable == true){
            int totalAmount = 0;
            vector<int> seatNums = flight->bookSeats(totalSeats, type);
            //totalAmount += seatNums.size() * (SeatType::BC) ? businessSeatFair : economySeatFair;
            totalAmount += seatNums.size() * ((type == SeatType::BC) ? businessSeatFair : economySeatFair);

            char mealRequired;
            cout<<"Meal Required (Y / N): ";
            cin>>mealRequired;
            totalAmount += (mealRequired == 'Y') ? seatNums.size() * 200 : 0;

            BookedTicket* ticket = new BookedTicket(bookingId++, flightNo, type, mealRequired, totalAmount, seatNums);
            flight->addBookedTicket(ticket);
            bookedTickets[ticket->getId()] = ticket;

            if(type == SeatType::BC) businessSeatFair += 200;
            else economySeatFair += 100;
        }else{
            cout<<"Seats are unavailable"<<endl;
        }
    }else{
        cout<<"Flight with the flight id is not available"<<endl;
        return;
    }
}

void AirlineManagementSystem::cancelTicket(){
    int bookingId;
    cout<<"Enter the bookingId: ";
    cin>>bookingId;

    //BookedTicket* ticket = bookedTickets[bookingId];
    auto it = bookedTickets.find(bookingId);
    if(it != bookedTickets.end()){
        BookedTicket* ticket = it->second;
        int flightNo = ticket->getFlightNo();
        Flight* flight = flights[flightNo];
        vector<int> bookedSeats = ticket->getSeatNos();
        flight->markSeatsAsAvailable(bookedSeats);
        ticket->cancelBooking();
    }else{
        cout<<"Please enter correct ticketID!!"<<endl;    
    }
}

void AirlineManagementSystem::viewFlightSummary(){
    for(auto it : flights){
        Flight* flight = it.second;
        flight->printSummary();
    }
}

void AirlineManagementSystem::viewBookingSummary(){
    cout<<'\n';
    for(auto it : bookedTickets){
        int id = it.first;
        BookedTicket* booking = it.second;

        if(booking->getBookingStatus() == BookingStatus::B){
            cout<<"Booking Id: "<<id<<endl;
            cout<<"flight Number: "<<booking->getFlightNo()<<endl;

            string seatType;
            if(booking->getSeatType() == SeatType::EC) seatType = "Economy";
            else seatType = "Business";
            cout<<seatType<<": ";
            for(auto num : booking->getSeatNos()){
                cout<<num<<", ";
            }
            cout<<endl;
            cout <<"Meal Required: " << ((booking->getMealRequired() == 'Y') ? "Yes" : "No")<<endl;
            cout<<"Total Cost: "<<booking->getTotalCost()<<endl;
            cout<<'\n';
        }else{
            cout<<"Booking Id: "<<booking->getId()<<endl;
            cout<<"Flight Number: "<<booking->getFlightNo()<<endl;
            cout<<"Cancelled"<<endl;
            cout<<"Total Cost: "<<400<<endl;
            cout<<'\n';
        }          
    }
}




