#pragma once
#include <bits/stdc++.h>
#include "Cab.hpp"
#include "CabDriver.hpp"
#include "Customer.hpp"
#include "Location.hpp"
#include "Ride.hpp"
#include "RideSummaryStrategy.hpp"
#include "CabDriverRideSummary.hpp"
#include "CustomerRideSummary.hpp"
using namespace std;

class ZulaCabApplication{
    private:
        static ZulaCabApplication* instance;
        int totalFare;
        int totalZulaCommission;
        int rideId;
        vector<Cab*> cabs;
        unordered_map<int, Ride*> ridesMap;
        unordered_map<int, CabDriver*> cabDriversMap;
        unordered_map<int, Customer*> customerMap;
        unordered_map<string, Location*> locationMap;
        ZulaCabApplication(){
            totalFare = 0;
            totalZulaCommission = 0;
            rideId = 0;
            cabs = vector<Cab*>();
            ridesMap = unordered_map<int, Ride*>();
            cabDriversMap = unordered_map<int, CabDriver*>();
            customerMap = unordered_map<int, Customer*>();
            locationMap = unordered_map<string, Location*>();
        }
    public:
        static ZulaCabApplication* getInstance();
        void intializeCabDrivers();
        void initalizeCustomers();
        void initializeLocation();
        void initializeCabLocation();
        CabDriver* cabDriverLogin();
        Customer* customerLogin();
        void HailCab();
        void displayCabDriverSmmary(CabDriver* driver);
        void displayCustomerSummary(Customer* customer);
        void displayAllCabsSummary();
        int calculateDistance(Location* source, Location* destination);
        int generateRideID();      
};