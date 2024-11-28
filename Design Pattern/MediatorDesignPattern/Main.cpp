#include <iostream>
#include "AuctionMediatorInterface.hpp"
#include "Auction.hpp"
#include "ColleagusInterface.hpp"
#include "Bidder.hpp"
using namespace std;

int main(){
    AuctionMediator* auction = new Auction();
    Colleagus* nithish = new Bidder("Nithish", auction);
    Colleagus* sriganesh = new Bidder("Sri Ganesh", auction);
    Colleagus* balaji = new Bidder("Balaji", auction);

    auction->addBidder(nithish);
    auction->addBidder(sriganesh);  
    auction->addBidder(balaji);

    nithish->placeBid(1000);  
}