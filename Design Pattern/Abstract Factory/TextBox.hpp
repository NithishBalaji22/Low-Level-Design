#pragma once
#include <iostream>
using namespace std;

class ITestBox{
    public:
        virtual void showText() = 0;
};

class winTextBox : public ITestBox{
    public:
        void showText() override{
            cout<<"Showing Windows Text Box !!!"<<endl;
        }
};

class macTextBox : public ITestBox{
    public:
        void showText() override{
            cout<<"Showing Mac Text Box !!!"<<endl;
        }
};