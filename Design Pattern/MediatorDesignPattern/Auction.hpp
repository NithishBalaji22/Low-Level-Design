#pragma once
#include <iostream>
#include <vector>
#include "AuctionMediatorInterface.hpp"
#include "ColleagusInterface.hpp"
using namespace std;

class Auction : public AuctionMediator{
    private:
        vector<Colleagus*> bidders;
    
    public:
        Auction(){
            bidders = vector<Colleagus*>();
        }

        void addBidder(Colleagus* bidder) override{
            bidders.emplace_back(bidder);
        }

        void placeBid(Colleagus* bidder, int bidAmount) override{
            for(auto b : bidders){
                if(bidder->getName() != b->getName()){
                    b->receiveBidNotification(bidder, bidAmount);
                }
            }
        }
};