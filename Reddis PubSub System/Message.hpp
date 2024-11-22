#pragma once
#include <iostream>
using namespace std;

class Message{
    private:
        string content;

    public:
        Message(string content){
            this->content = content;
        }

        string getMessage(){
            return content;
        }
};