#include <iostream>
#include "AirlineManagementSystem.hpp"
#include "Flight.hpp"
using namespace std;

int main(){
    AirlineManagementSystem* airline = AirlineManagementSystem::getInstance();

    // Creating Flights
    Flight* f1 = new Flight(101);
    Flight* f2 = new Flight(102);

    airline->addFlight(f1);
    airline->addFlight(f2);

    bool flag = true;
    while(flag){
        int option;
        cout<<"\n1. Book Ticket\n2. Cancel Ticket\n3. View Book Summary\n4. View FlightSummary\n5. Exit\n";
        cout<<"Choose an option: ";
        cin>>option;
        
        switch(option){
            case 1: 
                airline->bookTicket();
                break;

            case 2:
                airline->cancelTicket();
                break;

            case 3:
                airline->viewBookingSummary();
                break;

            case 4:
                airline->viewFlightSummary();
                break;

            case 5:
                flag = false;

            default:
                cout<<"Choose correct option!!!"<<endl;
                break;
        }
    }
}
