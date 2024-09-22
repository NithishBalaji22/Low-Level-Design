#pragma once
#include<iostream>
#include "Software.hpp"
using namespace std;

class Employee;
class Device;
class Installation{
    private:
        int id;
        Software* software;
        string installationDate;
        string expiryDate;

    public:
        Installation(int id, Software* software, string startDate, string endDate){
            this->id = id;
            this->software = software;
            software->incrementInstallation(1);
            installationDate = startDate;
            expiryDate = endDate;
        }

        int getId(){
            return id;
        }

        Software* getSoftware(){
            return software;
        }

        string getInstallationDate(){
            return installationDate;
        }

        string getExpiryDate(){
            return expiryDate;
        }
};