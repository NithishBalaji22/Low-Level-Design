#pragma once
#include <iostream>
#include <random>
using namespace std;

class Dice{
    public:
        int roll(){
            random_device rd; 
            mt19937 gen(rd());
            uniform_int_distribution<> dist(1, 6);

            // Generate a random number between 1 and 6
            int randomNum = dist(gen);
            return randomNum;
        }
};