#pragma once
#include <iostream>
using namespace std;

class Ladder{
    private:
        int start;
        int end;
    
    public:
        Ladder(int start, int end){
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