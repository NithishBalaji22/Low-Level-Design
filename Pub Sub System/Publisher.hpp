#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Message.hpp"
#include "Subscriber.hpp"
#include <set>
using namespace std;

class Publisher{
    private:
        vector<Subscriber*> subscribers;
        set<Message*> topics;

    public: 
        Publisher(){
            subscribers = vector<Subscriber*>();
            topics = set<Message*>();
        }

        void addSubscriber(Subscriber* user){
            subscribers.emplace_back(user);
        }

        void removeSubscriber(Subscriber* user){
            auto it = find(subscribers.begin(), subscribers.end(), user);
            if(it != subscribers.end()){
                cout<<"Removed Subscriber: "<<user->getName()<<endl;
                subscribers.erase(it);
            }else{
                cout<<"He is not your subscriber !!"<<endl;
            }            
        }

        void publish(Message* message){
            if(topics.find(message) == topics.end()){
                topics.insert(message);
                for(auto user : subscribers){
                    user->notify(message);
                }
            }else{
                cout<<"Publisher cant publish this topic because its already published !!"<<endl;
            }
        }
};
