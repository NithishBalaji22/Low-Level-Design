#pragma once
#include<iostream>
#include <cstdlib>
using namespace std;

class Dice{
    private:
        static const int MIN_VALUE = 1;
        static const int MAX_VALUE = 6;

    public:
        int roll(){
            return MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
        }
};