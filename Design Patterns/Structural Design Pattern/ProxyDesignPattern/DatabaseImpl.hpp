#pragma once
#include <iostream>
#include "DatabaseInterface.hpp"
using namespace std;

class DatabaseImplementation : public DatabaseInterface{    
    public:
        void create(string client, Employer* obj) override{
            cout<<"Employee has been created"<<endl;
        }

        void get(string client, int empId) override{
            cout<<"Data is fetched for the Employee ID: "<<empId<<endl;
        }

        void deleteRecord(string client, int empId){
            cout<<"Employee with the ID: "<<empId<<" got deleted"<<endl;
        }
};