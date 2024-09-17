#include "RideService.hpp"

RideService* RideService::instance = nullptr;

RideService* RideService::getInstance(){
    if(instance == nullptr){
        instance = new RideService;
    }
    return instance;
}

void RideService::registerPassenger(Passenger* passenger){
    passengers[passenger->getId()] = passenger;
}

void RideService::registerDriver(Driver* driver){
    drivers[driver->getId()] = driver;
}

void RideService::addToRideReqQueue(Ride* ride){
    rideReq.push(ride);
}

vector<Driver*> RideService::getDrivers(){
    vector<Driver*>v;
    for(auto it : drivers){
        v.emplace_back(it.second);
    }
    return v;
}

unordered_map<int, Ride*> RideService::getRide(){
    return rides;
}

Ride* RideService::requestRide(Passenger* passenger, char source, char destination){
    if(passengers.find(passenger->getId()) != passengers.end()){
        Ride* ride = new Ride(generateRideId(), passenger, nullptr, source, destination, RideStatus::REQUESTED);
        Driver* driver = notifyDrivers(ride);
        acceptRide(driver, ride);
        notifyDriver(ride);
        return ride;
    }
    return nullptr;    
}

int RideService::generateRideId(){
    return rand() % 100;
}

void RideService::acceptRide(Driver* driver, Ride* ride){
    Passenger* passenger = ride->getPassenger();
    if(driver != nullptr){
        ride->setDriver(driver);
        driver->setDriverStatus(DriverStatus::BUSY);
        ride->setStatus(RideStatus::ACCEPTED);
        notifyPassenger(ride);        
    }
}

void RideService::startRide(Ride* ride){
    if(ride->getRideStatus() == RideStatus::ACCEPTED){
        ride->setStatus(RideStatus::IN_PROGRESS);
        notifyPassenger(ride);
    }
}

void RideService::completeRide(Ride* ride){
    if(ride->getRideStatus() == RideStatus::IN_PROGRESS){
        ride->setStatus(RideStatus::COMPLETED);
        ride->getdriver()->setDriverStatus(DriverStatus::AVAILABLE);
        double totalFair = calculateFair(ride);
        ride->getdriver()->setDriverEarnings(totalFair);
        ride->getdriver()->setLocation(ride->getDestination());
        notifyPassenger(ride);
        notifyDriver(ride);
    }
}

void RideService::cancelRide(Ride* ride){
    if(ride->getRideStatus() == RideStatus::REQUESTED || ride->getRideStatus() == RideStatus::ACCEPTED){
        ride->setStatus(RideStatus::CANCELLED);
        if(ride->getdriver() != nullptr) ride->getdriver()->setDriverStatus(DriverStatus::AVAILABLE);
        notifyPassenger(ride);
        notifyDrivers(ride);
    }
}

double RideService::calculateFair(Ride* ride){
    double baseFair = 80;
    double perkmFair= 10;
    double calculateKm = abs(ride->getDestination() - ride->getSource());
    return baseFair + (perkmFair * calculateKm);
}


Driver* RideService::notifyDrivers(Ride* ride){
    Passenger* passenger = ride->getPassenger();
    char source = ride->getSource();
    char destination = ride->getDestination();
    int Minimum = INT_MAX;

    Driver* driver = nullptr;
    for(Driver* d : getDrivers()){
        if(d->getDriverStatus() == DriverStatus::AVAILABLE){
            if(abs(destination - d->getDriverLocation()) < Minimum){
                driver = d;
                Minimum = abs(destination - d->getDriverLocation());
            }else if (driver != nullptr && abs(destination - d->getDriverLocation()) == Minimum){
                if(d->getTotalEarnings() < driver->getTotalEarnings()){
                    driver = d;
                    Minimum = abs(destination - d->getDriverLocation());
                }
            }
        }                
    }  

    if(driver != nullptr){
        ride->setDriver(driver);
        notifyDriver(ride);
        notifyPassenger(ride);
    }    

    return driver;  
}

void RideService::notifyDriver(Ride* ride){
    Driver* driver = ride->getdriver();
    if(driver != nullptr){
        switch(ride->getRideStatus()){
            case RideStatus::COMPLETED:
                cout<<"Ride Completed and the fair is: "<<calculateFair(ride)<<'\n';
                break;

            case RideStatus::CANCELLED:
                cout<<"Ride has been cancelled by the passenger: "<<ride->getPassenger()->getName()<<'\n';
                break;
        }
    }
}

void RideService::notifyPassenger(Ride* ride){
    switch(ride->getRideStatus()){
        case RideStatus::ACCEPTED:
            cout<<"Your ride for the request from "<<ride->getSource()<<" to "<<ride->getDestination()<<" has been accpeted by the driver: "<<ride->getdriver()->getName()<<'\n';
            break;

        case RideStatus::IN_PROGRESS:
            cout<<"Your ride has started! Enjoy your ride! WhooW!"<<'\n';
            break;

        case RideStatus::COMPLETED:
            cout<<"Your ride has completed and the fair is: $"<<calculateFair(ride)<<'\n';
            break;

        case RideStatus::CANCELLED:
            cout<<"Your ride has been cancelled"<<'\n';
            break;  
    }
}
