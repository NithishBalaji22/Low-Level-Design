#pragma once
#include <iostream>
using namespace std;

class Colleagus{
    public:
        virtual void placeBid(int amount) = 0;
        virtual void receiveBidNotification(Colleagus* bidder, int newAmount) = 0;
        virtual string getName() = 0;
};