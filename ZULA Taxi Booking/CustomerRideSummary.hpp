#pragma once
#include <iostream>
#include "RideSummaryStrategy.hpp"
using namespace std;

class CustomerRideSummary : public RideSummaryStrategy{    
    public:
        CustomerRideSummary(string source, string destionation, int cabDetails, int fair): RideSummaryStrategy(source, destionation, cabDetails, fair){}

        string getSource(){
            return source;
        }

        string getDestination(){
            return destination;
        }

        int getDetails(){
            return details;
        }

        int getFare(){
            return fare;
        }

        int getZulaCommission(){
            return ZulaCommission;
        }

};