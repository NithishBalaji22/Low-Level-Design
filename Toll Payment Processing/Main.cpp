#include <iostream>
#include "Account.hpp"
#include "Car.hpp"
#include "CarType.hpp"
#include"Fuel.hpp"
#include "TollPaymentProcessing.hpp"
#include "User.hpp"
#include "UserCategory.hpp"
using namespace std;

int main(){
    TollPaymentProcessing* system = TollPaymentProcessing::getInstance();
    
    Account* account = new Account(1111, 2812, 100000);
    User* nithish = new User(1, "NithishBalaji", account, UserCategory::VIP);
    Car* car = new Car("TN59CB9015", "Audi", Fuel::DIESEL, CarType::LUXURY_CAR, 'A', 'E', nithish);

    Toll* toll1 = new Toll(1, 'B', 1000);
    Toll* toll2 = new Toll(2, 'C', 2000);
    Toll* toll3 = new Toll(3, 'F', 5000);

    system->registerToll(toll1);
    system->registerToll(toll2);
    system->registerToll(toll3);

    system->startJouney(car);
}