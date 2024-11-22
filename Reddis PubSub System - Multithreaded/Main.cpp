#include <iostream>
#include <thread>
#include "PubSubSystem.hpp"
#include "Consumers.hpp"
#include "Message.hpp"
#include "Subscriber.hpp"
#include "Topic.hpp"
using namespace std;

int main() {
    PubSubSystem* pubsub = new PubSubSystem();

    // Creating Topics
    Topic* newsletter = new Topic("NewsLetter");
    Topic* games = new Topic("Games");

    // Creating Subscribers
    Subscriber* nithish = new Consumer("Nithish");
    Subscriber* balaji = new Consumer("Balaji");
    Subscriber* sriganesh = new Consumer("Sri Ganesh");

    // Subscribing to Topics
    newsletter->addSubscriber(nithish);
    newsletter->addSubscriber(balaji);
    games->addSubscriber(sriganesh);

    // Registering Topics in the PubSubSystem
    pubsub->registerTopic(newsletter);
    pubsub->registerTopic(games);

    // Simulate concurrent publishing
    thread t1([&]() {
        pubsub->publish(newsletter, new Message("Trump won 2024 Election and he is 47th president of USA"));
    });

    this_thread::sleep_for(chrono::seconds(1));

    thread t2([&]() {
        pubsub->publish(games, new Message("New Game Released: Space Adventures!"));
    });

    // Join threads to ensure execution completes
    t1.join();
    t2.join();

    // Cleanup
    delete pubsub;
    delete newsletter;
    delete games;
    delete nithish;
    delete balaji;
    delete sriganesh;

    return 0;
}
