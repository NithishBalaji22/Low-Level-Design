#pragma once
#include<iostream>
using namespace std;

class RideSummaryStrategy{
    protected:
        string source;
        string destination;
        int details;
        int fare;
        int ZulaCommission;

    public:
        RideSummaryStrategy(string source, string destination, int details, int fare, int ZulaCommission = 0){
            this->source = source;
            this->destination = destination;
            this->details = details;
            this->fare = fare;
            this->ZulaCommission = ZulaCommission;
        }
        
        virtual string getSource() = 0;
        virtual string getDestination() = 0;
        virtual int getDetails() = 0;
        virtual int getFare() = 0;
        virtual int getZulaCommission() = 0;
};