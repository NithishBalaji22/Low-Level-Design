#include<bits/stdc++.h>
using namespace std;

#include"CarRentalSystem.hpp"
#include"Car.hpp"
#include"CarType.hpp"
#include"Customer.hpp"
#include"Reservation.hpp"

void displayAvailability(vector<Car*> cars){
    for(auto it : cars){
        cout<<it->getBrandName()<<" "<<it->getModelName()<<" "<<" is Available"<<'\n';
    }
}
int main(){
    CarRentalSystem* rentalSystem = CarRentalSystem::getInstance();
    
    //Register Customer
    Customer* cus1 = new Customer(1, "Nithish", "nithish@gamil.com", "1234567890", "IBLIBDIUGI", 10000);
    Customer* cus2 = new Customer(2, "Mani", "Mani@gamil.com", "6465439495", "FUONHOD", 20000);

    rentalSystem->registerCustomers(cus1);
    rentalSystem->registerCustomers(cus2);

    //Register Car
    Car* car1 = new Car(1, "Toyata", "Fortuner", 2020, CarType::DIESEL, 4000);
    Car* car2 = new Car(2, "Audi", "A6", 2022, CarType::PETROL, 8000);
    Car* car3 = new Car(3, "Mercedes", "S Class", 2022, CarType::PETROL, 10000);

    rentalSystem->registerCars(car1);
    rentalSystem->registerCars(car2);
    rentalSystem->registerCars(car3);

    vector<Car*> cars = rentalSystem->getAvailableCars();
    displayAvailability(cars);

    rentalSystem->bookCar(cus1, car1, 1, 2);
    cars = rentalSystem->getAvailableCars();
    displayAvailability(cars);

    rentalSystem->bookCar(cus2, car2, 1, 2);
    cars = rentalSystem->getAvailableCars();
    displayAvailability(cars);

    //CancelCar
    string reservationId;
    cout<<"Enter your reservation ID: ";
    cin>>reservationId;
    rentalSystem->cancelCar(reservationId);
    cars = rentalSystem->getAvailableCars();
    displayAvailability(cars);
}