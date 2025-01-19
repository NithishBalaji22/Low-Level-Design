#pragma once
#include <iostream>
using namespace std;

class Colleagus;
class AuctionMediator{
    public:
        virtual void addBidder(Colleagus* bidder) = 0;        
        virtual void placeBid(Colleagus* bidder, int amount) = 0;
};