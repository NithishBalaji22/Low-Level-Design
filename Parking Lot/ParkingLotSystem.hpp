#pragma once
#include <bits/stdc++.h>
#include "Account.hpp"
#include "Levels.hpp"
#include "Vehicle.hpp"
#include "VehicleType.hpp"
#include "PaymentFlowInterface.hpp"
#include "PaymentFlow.hpp"
#include "ParkingTicket.hpp"
using namespace std;

class ParkingLot{
    private:
        static int paymentId;
        static ParkingLot* instance;
        vector<Level*> levels;
        ParkingLot(){
            levels = vector<Level*>();
        }

        public:
            static ParkingLot* getInstance();
            void addLevel(Level* level);
            ParkingTicket* parkvehicle(Vehicle* vehicle);
            void unparkVehicle(ParkingTicket* ticket, Account* account);
            void displayAvailability();
            int generatePaymentId();
};

