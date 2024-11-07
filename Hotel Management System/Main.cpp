#include <iostream>
#include <vector>
#include "OnlineHotelBookingSystem.hpp"
#include "Account.hpp"
#include "Guest.hpp"
#include "Hotel.hpp"
#include "Room.hpp"
#include "RoomType.hpp"
#include "Reservation.hpp"
using namespace std;


int main(){
    OnlineHotelBookingSystem* system = OnlineHotelBookingSystem::getInstance();
    
    //Creating Account
    Account* account = new Account(1111,2812,100000);

    //Creating Guest
    Guest* nithish = new Guest("Nithish", "1234569870", "nithish@gmail.com", account);

    //Creating Hotels
    Hotel* hotel1 = new Hotel("HillTop", "Kodaikanal", "7894563214");
    Hotel* hotel2 = new Hotel("KolliHills", "Kolli Malai", "7894563214");
    Hotel* hotel3 = new Hotel("VarahaValley", "Kodaikanal", "7894563214");
    Hotel* hotel4 = new Hotel("KodaiHills", "Kodaikanal", "7894563214");
    Hotel* hotel5 = new Hotel("HeavenHills", "Kolli Malai", "7894563214");
    Hotel* hotel6 = new Hotel("KingHotel", "Ooty", "7894563214");

    //Adding hotels to the system
    system->addHotel(hotel1);
    system->addHotel(hotel2);
    system->addHotel(hotel3);
    system->addHotel(hotel4);
    system->addHotel(hotel5);
    system->addHotel(hotel6);

    //Loading Rooms to the Hotel
    system->loadRoomsToTheHotel(hotel1);
    system->loadRoomsToTheHotel(hotel2);
    system->loadRoomsToTheHotel(hotel3);
    system->loadRoomsToTheHotel(hotel4);
    system->loadRoomsToTheHotel(hotel5);
    system->loadRoomsToTheHotel(hotel6);

    //Booking
    Reservation* reservation = system->searchHotelInTheLocation(nithish, "Kodaikanal");
    system->viewSummary(reservation);
    nithish->showBalance();
    
    //Cancelling
    system->cancelRoomBooking(reservation->getReservationId());
    nithish->showBalance();
}