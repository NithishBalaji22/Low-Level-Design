#pragma once
#include "SubcriberInterface.hpp"
#include <iostream>
using namespace std;

class User : public ISubcribers{
    private:
        int userId;

    public:
        User(int userId){
            this->userId = userId;
        }

        void notify(string msg) override{
            cout<<"User "<<userId<<" has received a message: "<<msg<<endl;
        }
};