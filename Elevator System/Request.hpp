#pragma once
#include <iostream>
using namespace std;

class Request{
    private:
        int source;
        int destination;

    public:
        Request(int source, int destination){
            this->source = source;
            this->destination = destination;
        }

        int getSource(){
            return source;
        }

        int getDestination(){
            return destination;
        }
};