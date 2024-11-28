#pragma once
#include <iostream>
#include "DatabaseImpl.hpp"
#include "DatabaseInterface.hpp"
using namespace std;

class DatabaseProxy : public DatabaseInterface{
    private:
        DatabaseInterface* obj;

    public:
        DatabaseProxy(){
            obj = new DatabaseImplementation();
        }

        void create(string client, Employer* emp) override{
            if(client == "ADMIN"){
                obj->create(client, emp);                
            }else{
                cout<<"Only Admin has the authority to create a record for the employer"<<endl;
            }
        }

        void deleteRecord(string client, int empId) override{
            if(client == "ADMIN"){
                obj->deleteRecord(client, empId);
            }else{
                cout<<"Only Admin has the authority to delete a record for the employer"<<endl;
            }
        }

        void get(string client, int empId) override{
            if(client == "ADMIN" || client == "Employee"){
                obj->get(client, empId);
            }else{
                cout<<"Only Admin or the Employee got the access to get employee details"<<endl;
            }
        }
};