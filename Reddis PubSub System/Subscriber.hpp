#pragma once
#include <iostream>
using namespace std;

class Message;
class Subscriber{
    public:
        virtual void notify(Message* message) = 0;
        virtual string getName() = 0;
};