#include "CarRentalSystem.hpp"

CarRentalSystem* CarRentalSystem::instance = nullptr;

CarRentalSystem* CarRentalSystem::getInstance(){
    if(instance == nullptr){
        instance = new CarRentalSystem();
    }
    return instance;
}

void CarRentalSystem::registerCustomers(Customer* customer){
    customers[customer->getId()] = customer;
}

void CarRentalSystem::registerCars(Car* car){
    cars[car->getId()] = car;
}

vector<Car*> CarRentalSystem::getAvailableCars(){
    vector<Car*>v;
    for(auto it : cars){
        Car* car = it.second;
        if(car->getAvailability()){
            v.emplace_back(car);
        }
    }
    return v;
}

void CarRentalSystem::bookCar(Customer* customer, Car* car, int startDate, int endDate){
    int amount = calculateCost(car, startDate, endDate);
    bool payment = makePayment(customer, amount);
    if(payment){
        car->setAvailability(false);
        Reservation* reservation = new Reservation(customer, car, startDate, endDate, amount);
        reservations[reservation->getId()] = reservation;
        cout<<"Your reservation for the car has been successfull and your reservation ID is: "<<reservation->getId()<<'\n';
        return;
    }
    cout<<"Insufficient Funds!"<<'\n';
}

void CarRentalSystem::cancelCar(string reservationId){
    auto it = reservations.find(reservationId);
    if(it != reservations.end()){
        Reservation* reservation = it->second;
        Customer* customer = reservation->getCustomer();
        Car* car = reservation->getCar();
        int amount = reservation->getAmount();
        customer->credit(amount);
        car->setAvailability(true);
    }
}

bool CarRentalSystem::makePayment(Customer* customer, int amount){
    int balance = customer->getBalance();
    if(balance - amount >= 0){
        customer->debit(amount);
        return true;
    }
    return false;
}

int CarRentalSystem::calculateCost(Car* car, int startDate, int endDate){
    int carCost = car->getPerDayRentalCost();
    int numDays = endDate - startDate + 1;
    cout<<"Car per day rental cost: "<<carCost<<'\n';
    cout<<"Number of days you are takin: "<<numDays<<'\n';
    cout<<"Total Amount: "<<carCost*numDays<<'\n';
    return carCost * numDays;
}