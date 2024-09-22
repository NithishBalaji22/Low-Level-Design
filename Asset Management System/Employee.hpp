#pragma once
#include<iostream>
#include"Device.hpp"
#include"Installation.hpp"
#include <vector>
using namespace std;

class Employee{
    private:
        int id;
        string name;
        vector<Device*> devices;

    public:
        Employee(int id, string name){
            this->id = id;
            this->name = name;
            devices = vector<Device*>();
        }

        string getName(){
            return name;
        }

        int getId(){
            return id;
        }

        void addDevice(Device* device){
            devices.emplace_back(device);
        }

        vector<Device*> getDevice(){
            return devices;
        }

        int calculateNoOfSoftware(){
            int totalSoftware= 0;
            for(Device* device : devices){
                vector<Installation*> installations = device->getInstallation();
                for(Installation* installation : installations){
                    Software* software = installation->getSoftware();
                    if(software != nullptr){
                        totalSoftware += 1;
                    }
                }
            }
            return totalSoftware;
        }

        //Forgot to add
        int calculateAmountSpent() {
            int totalAmount = 0;
            for (Device* device : devices) {
                for (Installation* installation : device->getInstallation()) {
                    Software* software = installation->getSoftware();
                    if (software != nullptr) {
                        totalAmount += software->getCost();
                    }
                }
            }
            return totalAmount;
        }        
};