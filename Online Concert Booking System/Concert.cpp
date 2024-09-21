#include "Concert.hpp"

int Concert::concertIdGenerator = 1;

int Concert::getId(){
    return id;
}

string Concert::getConcertName(){
    return concertName;
}

string Concert::getArtist(){
    return artist;
}

string Concert::getVenue(){
    return venue;
}

vector<vector<Seat*>> Concert::getConcertSeats(){
    return seats;    
}

unordered_map<string, Seat*> Concert::getMapSeats(){
    return mapSeats;       
}

void Concert::incrementProfit(double amount){
    concertProfit += amount;
}

void Concert::decrementProfit(double amount){
    concertProfit -= amount;
}

double Concert::bookTicket(vector<pair<int,int>> bookedSeats){
    double totalPrice = 0;
    for(auto seatPair : bookedSeats){
        string seatId = to_string(seatPair.first) + '-' + to_string(seatPair.second);
        Seat* seat = mapSeats.at(seatId);  
        if(seat->getSeatStatus() == SeatStatus::AVAILABLE){
            totalPrice += seat->getPrice();  
        }else{
            cout << "Seat " << seatId << " is not available!" << endl;
        }
    }
    return totalPrice;
}

vector<Seat*> Concert::markSeatsAsOccupied(vector<pair<int,int>>bookedSeats){
    vector<Seat*> seatsBooked;
    for(auto it : bookedSeats){
        string seatId = to_string(it.first) + '-' + to_string(it.second);
        SeatStatus status = mapSeats.at(seatId)->getSeatStatus();
        if(status == SeatStatus::AVAILABLE){
            Seat* seat = mapSeats.at(seatId);
            seatsBooked.emplace_back(seat);
            seat->setSeatStatus(SeatStatus::OCCUPIED);
        }
    }
    return seatsBooked;   
}

void Concert::markSeatsAsAvailable(vector<Seat*>bookedSeats){
    for(Seat* seat : bookedSeats){
        seat->setSeatStatus(SeatStatus::AVAILABLE);
    } 
}

vector<vector<Seat*>> Concert::initializeSeats(int rows, int cols){
    vector<vector<Seat*>>s;
    for(int row=1; row<=rows; row++){
        vector<Seat*> rowSeats;
        for(int col=1; col<=cols; col++){
            string seatId = to_string(row) + '-' + to_string(col);
            SeatType type = (row <= 2) ? SeatType::PREMIUM : SeatType::NORMAL;
            double price = (type == SeatType::PREMIUM) ? 5000.0 : 3000.0;
            Seat* seat = new Seat(seatId, type, SeatStatus::AVAILABLE, price);
            rowSeats.emplace_back(seat);
            mapSeats.insert({seatId, seat});
        }
        s.emplace_back(rowSeats);
    }
    return s;
}