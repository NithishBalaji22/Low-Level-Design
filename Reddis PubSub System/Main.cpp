#include <iostream>
#include "PubSubSystem.hpp"
#include "Consumers.hpp"
#include "Message.hpp"
#include "Subscriber.hpp"
#include "Topic.hpp"
using namespace std;

int main(){
    PubSubSystem* pubsub = new PubSubSystem();

    // Creating Topic
    Topic* newsletter = new Topic("NewsLetter");
    Topic* games = new Topic("Games");

    // Creating Subscriber and subscribing them to the newsletter topic
    Subscriber* nithish = new Consumer("Nithish");
    Subscriber* balaji = new Consumer("Balaji");

    newsletter->addSubscriber(nithish);
    newsletter->addSubscriber(balaji);

    Subscriber* sriganesh = new Consumer("Sri Ganesh");
    games->addSubscriber(sriganesh);

    pubsub->registerTopic(newsletter);
    pubsub->registerTopic(games);

    pubsub->publish(newsletter, new Message("Trump won 2024 Election and he is 47th president of USA"));
}