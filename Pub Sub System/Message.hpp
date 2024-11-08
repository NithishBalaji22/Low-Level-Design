#pragma once
#include <iostream>
using namespace std;

class Message{
    private:
        string message;
    public:
        Message(string message){
            this->message = message;
        }

        string getMessage(){
            return message;
        }
};