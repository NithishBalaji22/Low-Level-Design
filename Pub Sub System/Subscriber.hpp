#pragma once
#include <iostream>
#include "Message.hpp"
using namespace std;

class Subscriber{
    public:
        virtual void notify(Message* message) = 0;
        virtual string getName() = 0;
};

class User : public Subscriber{
    private:
        string name;
    public:
        User(string name) : name(name) {}

        void notify(Message* message){
            cout<<"Subscriber " << name << " received a message: " << message->getMessage()<<endl;
        }

        string getName(){
            return name;
        }
};