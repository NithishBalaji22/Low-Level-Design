#include <iostream>
#include "Message.hpp"
#include "Publisher.hpp"
#include "Subscriber.hpp"
using namespace std;

int main(){
    Subscriber* nithish = new User("Nithish");
    Subscriber* balaji = new User("Balaji");

    Publisher* sriganesh = new Publisher();
    sriganesh->addSubscriber(nithish);
    sriganesh->addSubscriber(balaji);

    Message* message = new Message("Currently the time is 2 am and currently learning Observer DP");
    sriganesh->publish(message);

    //Remove Subscriber
    sriganesh->removeSubscriber(balaji);
    Message* message2 = new Message("You will get into Zoho :)");
    sriganesh->publish(message2);

}