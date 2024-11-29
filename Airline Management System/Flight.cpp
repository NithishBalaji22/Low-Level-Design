#include "Flight.hpp"

Flight::Flight(int id){
    this->id = id;
    int rows = ROWS;
    int cols = COLS;
    seats = vector<vector<Seat *>>(rows, vector<Seat *>(cols));
    bookedTickets = vector<BookedTicket *>();
    initializeSeats();
}

int Flight::getId(){
    return id;
}

void Flight::addBookedTicket(BookedTicket *ticket){
    bookedTickets.emplace_back(ticket);
}

void Flight::initializeSeats(){
    int rows = seats.size();
    int cols = seats[0].size();
    int seatNo = 1;
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){
            SeatType type = (row == 0) ? SeatType::BC : SeatType::EC;
            seats[row][col] = new Seat(seatNo++, type);
        }
    }
}

bool Flight::areSeatsAvailable(int numSeats, SeatType type){
    int seatAvailableCount = 0;
    int rows = seats.size();
    int cols = seats[0].size();

    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){
            Seat *seat = seats[row][col];
            if (seat->getAvailability() == SeatAvailability::AVAILABLE && seat->getSeatType() == type){
                seatAvailableCount++;
            }
        }
    }
    return seatAvailableCount >= numSeats;
}

vector<int> Flight::bookSeats(int numSeats, SeatType type){
    vector<int> seatsBooked;
    int rows = seats.size();
    int cols = seats[0].size();

    for (int row = 0; row < rows && numSeats > 0; row++){
        for (int col = 0; col < cols && numSeats > 0; col++){
            Seat *seat = seats[row][col];
            if (seat->getAvailability() == SeatAvailability::AVAILABLE && seat->getSeatType() == type){
                seat->seatOccupied();
                seatsBooked.emplace_back(seat->getId());
                numSeats--;
            }
        }
    }

    return seatsBooked;
}

void Flight::markSeatsAsAvailable(vector<int> seats_){
    int rows = seats.size();
    int cols = seats[0].size();
    int index = 0;

    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){
            Seat *seat = seats[row][col];
            if (seat->getAvailability() == SeatAvailability::OCCUPIED && seat->getId() == seats_[index]){
                seat->seatAvailable();
                index++;
            }
        }
    }
}

void Flight::printSummary(){
    cout<<'\n';
    cout << "Summary for the Flight Number: " << id<<endl;
    cout << "Seats Booked: ";
    for (auto ticket : bookedTickets){
        auto seatNo = ticket->getSeatNos();
        for (auto num : seatNo){
            cout << num << "," << " ";
        }
    }

    cout<<endl;
    cout << "Meals Booked: ";
    for (auto ticket : bookedTickets){
        vector<int> mealBookedSeats;
        if (ticket->getMealRequired() == 'Y'){
            auto seatNo = ticket->getSeatNos();
            for (auto num : seatNo){
                cout << num << ", ";
            }
        }
    }

    cout<<endl;
    cout << "Total Cost: ";
    int totalCost = 0;
    for (auto ticket : bookedTickets){
        totalCost += ticket->getTotalCost();
    }
    cout << totalCost << endl;

    cout << "Seats Available: ";
    int rows = seats.size();
    int cols = seats[0].size();

    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){
            Seat *seat = seats[row][col];
            if (seat->getAvailability() == SeatAvailability::AVAILABLE){
                cout << seat->getId() << ", ";
            }
        }
    }
    cout<<endl;
}