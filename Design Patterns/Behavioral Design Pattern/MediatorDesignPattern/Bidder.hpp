#pragma once
#include <iostream>
#include "ColleagusInterface.hpp"
#include "AuctionMediatorInterface.hpp"
using namespace std;

class Bidder : public Colleagus{
    private:
        string name;
        AuctionMediator* auction;

    public:
        Bidder(string name, AuctionMediator* auction){
            this->name = name;
            this->auction = auction;
        }

        void placeBid(int amount) override{
            auction->placeBid(this, amount);
        }

        void receiveBidNotification(Colleagus* bidder, int newAmount) override{
            cout<<bidder->getName()<<" has been placed a bid and the amount is: "<<newAmount<<endl;
        }

        string getName() override{
            return name;
        }
};