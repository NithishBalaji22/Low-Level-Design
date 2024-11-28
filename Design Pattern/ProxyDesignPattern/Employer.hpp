#pragma once
#include <iostream>
using namespace std;

class Employer{
    private:
        int empId;
        string name;

    public:
        Employer(int empId, string name){
            this->empId = empId;
            this->name = name;
        }

};