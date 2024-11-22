#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <mutex>
#include <thread>
#include "Subscriber.hpp"
using namespace std;

class Message;

class Topic {
private:
    string name;
    unordered_set<Subscriber*> subscribers;
    mutable mutex mtx; // Mutex to ensure thread safety

public:
    Topic(string topicName) : name(topicName) {}

    string getTopicName() {
        return name;
    }

    void addSubscriber(Subscriber* subscriber) {
        lock_guard<mutex> lock(mtx);
        subscribers.insert(subscriber);
    }

    void removeSubscriber(Subscriber* subscriber) {
        lock_guard<mutex> lock(mtx);
        if (subscribers.find(subscriber) != subscribers.end()) {
            cout << "Subscriber: " << subscriber->getName() << " has been removed!!" << endl;
            subscribers.erase(subscriber);
        } else {
            cout << "Subscriber is not present in our subscription" << endl;
        }
    }

    void publish(Message* message) {
        lock_guard<mutex> lock(mtx);
        vector<thread> threads;

        for (auto subscriber : subscribers) {
            // Notify each subscriber in a separate thread
            threads.emplace_back([subscriber, message]() {
                subscriber->notify(message);
            });
        }

        // Join all threads to ensure delivery is complete
        for (auto& t : threads) {
            t.join();
        }
    }
};
