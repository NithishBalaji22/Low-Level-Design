#pragma once
#include <bits/stdc++.h>
#include <thread>
#include "Account.hpp"
#include "Guest.hpp"
#include "Hotel.hpp"
#include "Payment.hpp"
#include "PaymentCredit.hpp"
#include "PaymentDebit.hpp"
#include "Reservation.hpp"
#include "Room.hpp"
#include "RoomType.hpp"
using namespace std;

class OnlineHotelBookingSystem{
    private:
        static OnlineHotelBookingSystem* instance;
        static int paymentId;
        static int reservationId;
        unordered_map<string, vector<Hotel*>> hotels; //Location Hotel
        unordered_map<string, Hotel*> hotelMap; // HotelName Hotel
        unordered_map<int, Reservation*> reservationHistory;
        unordered_map<int, Payment*> refundHistory;
        OnlineHotelBookingSystem(){
            paymentId = 1;
            reservationId = 1;
            hotelMap = unordered_map<string, Hotel*>();
            hotels = unordered_map<string, vector<Hotel*>>();     
            reservationHistory = unordered_map<int, Reservation*>();   
            refundHistory = unordered_map<int, Payment*>();
        }

    public:
        static OnlineHotelBookingSystem* getInstance();
        void loadRoomsToTheHotel(Hotel* hotel);
        void addHotel(Hotel* hotel);
        Reservation* searchHotelInTheLocation(Guest* user, string location);
        Reservation* bookRoom(Guest* user, Hotel* hotel);
        void cancelRoomBooking(int id);
        Payment* makePayment(Guest* user, Room* room, Hotel* hotel, int checkInDate, int checkOutDate);
        void viewSummary(Reservation* reservation);
        int generatePaymentId();
        int generateReservationId();
};