#pragma once
#include <iostream>
using namespace std;

class User{
    private:
        int id;
        string name;
        string emailId;
        string phoneNumber;

    public:
        User(int id, string name, string emailId, string phoneNumber){
            this->id = id;
            this->name = name;
            this->emailId = emailId;
            this->phoneNumber = phoneNumber;
        }

        int getId(){
            return id;
        }

        string getName(){
            return name;
        }

        string getEmailId(){
            return emailId;
        }

        string getPhoneNumber(){
            return phoneNumber;
        }
};