#pragma once
#include <iostream>
using namespace std;

class IButton{
    public:
        virtual void pressButton() = 0;
};

class winButton : public IButton{
    public:
        void pressButton() override{
            cout<<"Pressing Windows Button !!"<<endl;
        }
};

class macButton : public IButton{
    public:
        void pressButton() override{
            cout<<"Pressing Mac Button !!"<<endl;
        }
};