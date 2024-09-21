#pragma once
#include<bits/stdc++.h>
#include "Customer.hpp"
#include "Car.hpp"
#include"Reservation.hpp"
#include"CarType.hpp"
using namespace std;

class CarRentalSystem{
    private:
        static CarRentalSystem* instance;
        unordered_map<int, Customer*> customers;
        unordered_map<int, Car*> cars;
        unordered_map<string, Reservation*> reservations;
        CarRentalSystem(){
            customers = unordered_map<int, Customer*>();
            cars = unordered_map<int, Car*>();
            reservations = unordered_map<string, Reservation*>();
        }

    public:
        static CarRentalSystem* getInstance();
        void registerCustomers(Customer* customer);
        void registerCars(Car* car);
        int calculateCost(Car* car, int startDate, int endDate);
        vector<Car*> getAvailableCars();
        void bookCar(Customer* customer, Car* car, int startDate, int endDate);
        void cancelCar(string reservationId);
        bool makePayment(Customer* customer, int amount);
};