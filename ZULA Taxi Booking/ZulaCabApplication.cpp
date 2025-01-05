#include "ZulaCabApplication.hpp"
const double ZULACOMMISSION = 0.3;

ZulaCabApplication* ZulaCabApplication::instance = nullptr;
ZulaCabApplication* ZulaCabApplication::getInstance(){
    if(instance == nullptr){
        instance = new ZulaCabApplication();
    }
    return instance;
}

void ZulaCabApplication::intializeCabDrivers(){
    CabDriver* aaa = new CabDriver(1, "aaa", 111, 25);
    CabDriver* bbb = new CabDriver(2, "bbb", 222, 36);
    CabDriver* ccc = new CabDriver(3, "ccc", 333, 31);
    CabDriver* ddd = new CabDriver(4, "ddd", 444, 28);
    cabDriversMap[1] = aaa;
    cabDriversMap[2] = bbb;
    cabDriversMap[3] = ccc;
    cabDriversMap[4] = ddd;
}

void ZulaCabApplication::initalizeCustomers(){
    Customer* WW = new Customer(1, "WW", 55, 25);
    Customer* xx = new Customer(2, "xx", 66, 36);
    Customer* yy = new Customer(3, "yy", 77, 31);
    Customer* zz = new Customer(4, "zz", 88, 28);

    customerMap[1] = WW;
    customerMap[2] = xx;
    customerMap[3] = yy;
    customerMap[4] = zz;
}

void ZulaCabApplication::initializeLocation(){
    Location* locA = new Location(1,"A",0);
    Location* locC = new Location(3,"C",4);
    Location* locD = new Location(4,"D",7);
    Location* locF = new Location(6,"F",9);
    Location* locB = new Location(2,"B",15);
    Location* locG = new Location(7,"G",18);
    Location* locH = new Location(8,"H",20);
    Location* locR = new Location(5,"R",23);

    locationMap["A"] = locA;
    locationMap["C"] = locC;
    locationMap["D"] = locD;
    locationMap["F"] = locF;
    locationMap["B"] = locB;
    locationMap["G"] = locG;
    locationMap["H"] = locH;
    locationMap["R"] = locR;
}

void ZulaCabApplication::initializeCabLocation(){
    Cab* c1 = new Cab(1, "D");
    Cab* c2 = new Cab(2, "G");
    Cab* c3 = new Cab(3, "H");
    Cab* c4 = new Cab(4, "A");

    cabs.emplace_back(c1);
    cabs.emplace_back(c2);
    cabs.emplace_back(c3);
    cabs.emplace_back(c4);
}

CabDriver* ZulaCabApplication::cabDriverLogin(){
    int id, password;
    cout<<"Enter your ID: "<<endl;
    cin>>id;

    auto it = cabDriversMap.find(id);
    if(it != nullptr){
        CabDriver* driver = it->second;
        cout<<"Enter your Password: "<<endl;
        cin>>password;
        if(driver->getPassword() != password){
            cout<<"Invalid Password!!"<<endl;
            return nullptr;
        }
        return driver;        
    }else{
        cout<<"Invalid ID!!"<<endl;
    }
    return nullptr;
}

Customer* ZulaCabApplication::customerLogin(){
    int id, password;
    cout<<"Enter your ID: "<<endl;
    cin>>id;

    auto it = customerMap.find(id);
    if(it != nullptr){
        Customer* customer = it->second;
        cout<<"Enter your Password: "<<endl;
        cin>>password;
        if(customer->getPassword() != password){
            cout<<"Invalid Password!!"<<endl;
            return nullptr;
        }
        return customer;        
    }else{
        cout<<"Invalid ID!!"<<endl;
    }
    return nullptr;
}

void ZulaCabApplication::HailCab(){
    Customer* customer = customerLogin();
    if(customer != nullptr){
        string source, destination;
        cout<<"Enter your Source Location: "<<endl;
        cin>>source;
        cout<<"Enter your Destination Location: "<<endl;
        cin>>destination;   

        Location* sourceLocation = locationMap.at(source);
        Location* destinationLocation = locationMap.at(destination);

        int minDistance = INT_MAX;
        Cab* nearstCab = nullptr;
        for(auto cab : cabs){
            Location* cabLocation = locationMap.at(cab->getLocation());
            int distance = calculateDistance(cabLocation, sourceLocation);
            if(distance < minDistance){
                minDistance = distance;
                nearstCab = cab;
            }
        }

        if(nearstCab != nullptr){
            int distance = calculateDistance(sourceLocation, destinationLocation);

            int fare = distance * 10;
            int ZulaCommission = fare * ZULACOMMISSION;

            totalFare += fare;
            totalZulaCommission += ZulaCommission;

            cout<<"Nearest Cab has been found and the estimated fare for this trip is: "<<fare<<endl;
            nearstCab->setLocation(destinationLocation->getLocationName());

            int rideId = generateRideID();
            Ride* ride = new Ride(rideId, sourceLocation->getLocationName(), destinationLocation->getLocationName(), customer, nearstCab, fare, ZulaCommission);
            RideSummaryStrategy* cabDriverSummary = new CabDriverRideSummary(sourceLocation->getLocationName(), destinationLocation->getLocationName(), customer->getId(), fare, ZulaCommission);
            RideSummaryStrategy* customerSummary = new CustomerRideSummary(sourceLocation->getLocationName(), destinationLocation->getLocationName(), nearstCab->getId(), fare);

            CabDriver* driver = cabDriversMap.at(nearstCab->getId());

            driver->addRide(cabDriverSummary);
            customer->addRide(customerSummary);
            nearstCab->addRide(cabDriverSummary);

            ridesMap[rideId] = ride;
            cout<<"Ride Initiated and the CabID: "<<nearstCab->getId()<<endl;
        }else{
            cout<<"Cab is not available!!"<<endl;
        }
    }else{
        return;
    }
}

void ZulaCabApplication::displayCabDriverSmmary(CabDriver* driver){
    cout<<"Cab Driver Id: "<<driver->getId()<<endl;
    cout<<"Cab Driver Name: "<<driver->getName()<<endl;
    cout<<"Trip Details: "<<endl;
    cout<<"Source\tDestination\tCustomer ID\tFare\tZULA Commission";
    vector<RideSummaryStrategy*> rides = driver->getDriverRides();
    for(auto ride : rides){
        cout<<ride->getSource()<<'\t'<<ride->getDestination()<<'\t'<<ride->getDetails()<<'\t'<<ride->getFare()<<'\t'<<ride->getZulaCommission()<<endl;
    }
}

void ZulaCabApplication::displayCustomerSummary(Customer* customer){
    cout<<"Customer Driver Id: "<<customer->getId()<<endl;
    cout<<"Customer Driver Name: "<<customer->getName()<<endl;
    cout<<"Trip Details: "<<endl;
    cout<<"Source\tDestination\tCab ID\tFare";
    vector<RideSummaryStrategy*> rides = customer->getCustomerRides();
    for(auto ride : rides){
        cout<<ride->getSource()<<'\t'<<ride->getDestination()<<'\t'<<ride->getDetails()<<'\t'<<ride->getFare()<<endl;
    }
}

void ZulaCabApplication::displayAllCabsSummary(){
    for(auto cab : cabs){
        cout<<"Cab ID: "<<cab->getId()<<endl;
        cout<<"Total Number of Trips: "<<cab->getRides().size()<<endl;
        cout<<"Total Fare Collected: "<<cab->getTotalFareCollected()<<endl;
        cout<<"Total Zula Commission: "<<cab->getTotalZulaCommission()<<endl;

        vector<RideSummaryStrategy*> rides = cab->getRides();
        cout<<"Source\tDestination\tCustomer Detail\tFare\tZula Commission"<<endl;
        for(auto ride : rides){
            cout<<ride->getSource()<<'\t'<<ride->getDestination()<<'\t'<<ride->getFare()<<'\t'<<ride->getZulaCommission()<<endl;
        }
    }
}

int ZulaCabApplication::calculateDistance(Location* source, Location* destination){
    return abs(source->getDistanceFromTheOrgin() - destination->getDistanceFromTheOrgin());
}

int ZulaCabApplication::generateRideID(){
    return ++rideId;
}