#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "Subscriber.hpp"
using namespace std;

class Message;
class Topic{
    private:
        string name;
        unordered_set<Subscriber*> subscribers;

    public:
        Topic(string topicName){
            this->name = topicName;
            subscribers = unordered_set<Subscriber*>();
        }

        string getTopicName(){
            return name;
        }

        void addSubscriber(Subscriber* subscriber){
            subscribers.insert(subscriber);
        }

        void removeSubscriber(Subscriber* subscriber){
            if(subscribers.find(subscriber) != subscribers.end()){
                cout<<"Subscriber: "<<subscriber->getName()<<" has been removed!!"<<endl;
                subscribers.erase(subscriber);
            }else{
                cout<<"Subscriber is not present in our subscription"<<endl;
            }
        }

        void publish(Message* message){
            for(auto it : subscribers){
                it->notify(message);
            }
        }
};