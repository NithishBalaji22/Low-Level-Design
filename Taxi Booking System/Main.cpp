#include<iostream>
using namespace std;

#include"RideService.hpp"
#include"Driver.hpp"
#include"DriverStatus.hpp"
#include"Passenger.hpp"
#include"Ride.hpp"
#include"RideStatus.hpp"

int main(){
    RideService* rideService = RideService::getInstance();

    //Passengers
    Passenger* p1 = new Passenger(1, "Nithish", "nithishbalaji2812@gamil.com", "8754685518", 'A');
    Passenger* p2 = new Passenger(2, "Sri Ganesh", "sriganesh.768@gamil.com", "8754685519", 'C');

    //Registering Passenger
    rideService->registerPassenger(p1);
    rideService->registerPassenger(p2);

    //Drivers
    Driver* d1 = new Driver(1, "Kanagalingam", "kanaga@12345", "66516515");
    Driver* d2 = new Driver(2, "Muthu Manoj", "Muthu@12345", "616566761");

    rideService->registerDriver(d1);
    rideService->registerDriver(d2);

    //Passenger 1 Requesting a ride
    Ride* ride = rideService->requestRide(p1, p1->getLocation(), 'C');

    //Starting the ride
    if(ride != nullptr) rideService->startRide(ride);

    //Complete the ride
    rideService->completeRide(ride);

    //Passenger 2 Requesting a ride form C to D so the driver who took the first call from A to C 
    //has to take this call too because he is the one at C
    Ride* ride2 = rideService->requestRide(p2, p2->getLocation(), 'D');

    //Starting the ride
    if(ride2 != nullptr) rideService->startRide(ride2);

    //Complete the ride
    rideService->completeRide(ride2);
}