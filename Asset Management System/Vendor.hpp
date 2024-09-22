#pragma once
#include <iostream>
#include <unordered_map>
#include "Software.hpp"
using namespace std;

class Vendor{
    private:
        int id;
        string name;
        unordered_map<string, Software*> softwares;
        int softwareInstallation= 0;
        int totalAmount;

    public:
        Vendor(int id, string name){
            this->id = id;
            this->name = name;
            softwares = unordered_map<string, Software*>();
            totalAmount = 0;
            softwareInstallation= 0;
        }

        string getName(){
            return name;
        }
        
        void addSoftware(Software* software){
            softwares[software->getName()] = software;
        }

        void amountSpent(int amount){
            totalAmount += amount;
            softwareInstallation++;
        }

        int getSoftwareInstallation(){
            return softwareInstallation;
        }

        int getAmountSpent(){
            return totalAmount;
        }

        Software* getSoftware(string softwareName){
            auto it = softwares.find(softwareName);
            if(it != softwares.end()){
                return it->second;
            }
            return nullptr;
        }
        
};