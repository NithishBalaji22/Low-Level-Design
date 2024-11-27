#pragma once
#include <iostream>
using namespace std;

class AcConditioner{
    private:
        bool isAcOn;
        int temparature;

    public:
        AcConditioner () {}

        void acOn(){
            isAcOn = true;
            cout<<"Ac has been turned on"<<endl;
        }

        void acOff(){
            isAcOn = false;
            cout<<"Ac has been turned off"<<endl;
        }

        void setTemparature(int tmp){
            temparature = tmp;
        }
};