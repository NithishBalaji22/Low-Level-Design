#pragma once
#include <iostream>
using namespace std;

class Employer;
class DatabaseInterface{
    public:
        virtual void create(string client, Employer* obj) = 0;
        virtual void deleteRecord(string client, int employeeId) = 0;
        virtual void get(string client, int employeeId)= 0;
};