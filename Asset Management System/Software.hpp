#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Software{
    private:
        int id;
        string name;
        string licenseNumber;
        int cost;
        int validityYear;
        int installationNo;
        int amountSpent= 0;

    public:
        Software(int id, string name, int cost, int validityYear){
            this->id = id;
            this->name = name;
            licenseNumber = generateLicenseNum();
            this->cost = cost;
            this->validityYear = validityYear;
            installationNo = 0;
            amountSpent = 0;
        }

        int getId(){
            return id;
        }

        string getName(){
            return name;
        }

        string getLicenseNumber(){
            return licenseNumber;
        }

        int getCost(){
            return cost;
        }

        int getValidityYear(){
            return validityYear;
        }

        int getAmountSpent(){
            return amountSpent;
        }

        int getInstallation(){
            return installationNo;
        }

        void incrementInstallation(int installation){
            amountSpent += cost;
            installationNo += installation;
        }

        void setValidityYear(int year){
            validityYear = year;
        }

        string generateLicenseNum(){
            srand(time(0));
            long long num = 1000000000 + rand() % 9000000000;
            return to_string(num);            
        }
};