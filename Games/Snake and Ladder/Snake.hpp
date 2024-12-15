#pragma once
#include <iostream>
using namespace std;

class Snake{
    private:
        int start;
        int end;
    
    public:
        Snake(int start, int end){
            this->start = start;
            this->end = end;
        }

        int getStart(){
            return start;
        }

        int getEnd(){
            return end;
        }
};