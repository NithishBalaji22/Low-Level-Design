#pragma once
#include <iostream>
using namespace std;

class Customer{
    private:
        string id;
        string name;
        string emailId;
        string phoneNumber;

    public:
        Customer(string id, string name, string emailId, string phoneNumber){
            this->id = id;
            this->name = name;
            this->emailId = emailId;
            this->phoneNumber = phoneNumber;
        }

        string getCustomerId(){
            return id;
        }

        string getlast4letters(){
            return name.substr(name.size()-4);
        }
};