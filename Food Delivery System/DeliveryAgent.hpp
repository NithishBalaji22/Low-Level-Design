#pragma once
#include <iostream>
using namespace std;

class DeliveryAgent{
    private:
        string id;
        string name;
        string emailId;
        string phoneNumber;
        bool isAvailable;
    
    public:
        DeliveryAgent(string id, string name, string emailId, string phoneNumber, bool status){
            this->id = id;
            this->name = name;
            this->emailId = emailId;
            this->phoneNumber = phoneNumber;
            isAvailable = status;
        }

        string getDeliveryAgentId(){
            return id;
        }

        bool getDeliveryAgentAvailability(){
            return isAvailable;
        }

        void setDeliveryAgentAvailability(bool status){
            isAvailable = status;
        }
};