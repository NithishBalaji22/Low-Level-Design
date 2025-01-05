#pragma once
#include <iostream>
#include "RideSummaryStrategy.hpp"
using namespace std;

class CabDriverRideSummary : public RideSummaryStrategy{
    public:
        CabDriverRideSummary(string source, string destionation, int customerDetails, int fare, int ZulaCommission) : RideSummaryStrategy(source, destination, customerDetails, fare, ZulaCommission) {}

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