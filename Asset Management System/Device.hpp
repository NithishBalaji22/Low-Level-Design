#pragma once
#include<iostream>
#include <vector>
#include "Installation.hpp"
using namespace std;

class Device{
    private:
        int id;
        string name;
        vector<Installation*> installations;
        
    public:
        Device(int id, string name){
            this->id = id;
            this->name = name;
            installations = vector<Installation*>();
        }

        int getId(){
            return id;
        }

        vector<Installation*> getInstallation(){
            return installations;
        }

        void addInstallation(Installation* installation){
            installations.emplace_back(installation);
        }

        //Forgot to add
        bool hasExpiredSoftware(const string& currentDate) {
            for (Installation* installation : installations) {
                if (installation->getExpiryDate() < currentDate) {
                    return true;
                }
            }
            return false;
        }


        int getTotalSoftwareInstalled(){
            return installations.size();
        }
};