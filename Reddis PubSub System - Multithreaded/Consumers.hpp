#pragma once
#include <iostream>
#include "Subscriber.hpp"
#include "Message.hpp"
using namespace std;

class Consumer : public Subscriber{
    private:
        string name;

    public:
        Consumer(string name){
            this->name = name;
        }

        void notify(Message* message){
            cout<<"Subscriber name: "<<name<<" has received a message "<<message->getMessage()<<endl;
        }

        string getName(){
            return name;
        }
};