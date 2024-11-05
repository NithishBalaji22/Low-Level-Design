#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Pass;
class Toll{
    private:
        int tollId;
        vector<Pass*> tollPass;
        char location;
        int baseCharge;
        int amountCollected;

    public:
        Toll(int tollId, char location, int baseCharge){
            this->tollId = tollId;
            this->tollPass = vector<Pass*>();
            this->location = location;
            this->baseCharge = baseCharge;
            amountCollected  = 0;
        }

        void addPass(Pass* pass){
            tollPass.emplace_back(pass);
        }

        int getBaseCharge(){
            return baseCharge;
        }

        char getLocation(){
            return location;
        }

        void addAmountCollect(int amount){
            amountCollected += amount;
        }
};