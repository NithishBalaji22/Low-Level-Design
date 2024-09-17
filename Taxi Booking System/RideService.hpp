#pragma once
#include<bits/stdc++.h>
using namespace std;

#include"Driver.hpp"
#include"DriverStatus.hpp"
#include"Passenger.hpp"
#include"Ride.hpp"
#include"RideStatus.hpp"

class RideService{
    private:
        static RideService* instance;
        unordered_map<int, Passenger*> passengers;
        unordered_map<int, Driver*> drivers;
        unordered_map<int, Ride*> rides;
        queue<Ride*> rideReq;
        RideService(){
            passengers = unordered_map<int, Passenger*>();
            drivers= unordered_map<int, Driver*>();
            rides= unordered_map<int, Ride*>();
            rideReq = queue<Ride*>();
        }

    public:
        static RideService* getInstance();
        void registerPassenger(Passenger* passenger);
        void registerDriver(Driver* driver);
        void addToRideReqQueue(Ride* ride);
        unordered_map<int, Ride*> getRide();
        Ride* requestRide(Passenger* passenger, char source, char destination);
        void acceptRide(Driver* driver, Ride* ride);
        void startRide(Ride* ride);
        void completeRide(Ride* ride);
        void cancelRide(Ride* ride);
        vector<Driver*> getDrivers();
        Driver* notifyDrivers(Ride* ride);
        void notifyPassenger(Ride* ride);
        void notifyDriver(Ride* ride);
        double calculateFair(Ride* ride);
        int generateRideId();
};