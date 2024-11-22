#pragma once
#include <iostream>
#include <unordered_set> 
#include "Topic.hpp"
using namespace std;

class PubSubSystem{
    private:
        unordered_set<Topic*> topics;

    public:
        PubSubSystem(){
            topics = unordered_set<Topic*>();
        }

        void registerTopic(Topic* topic){
            topics.insert(topic);
        }

        void publish(Topic* topic, Message* message){
            if(topics.find(topic) != topics.end()){
                topic->publish(message);                
            }else{
                cout<<"Topic has not found!!"<<endl;
            }
        }
};