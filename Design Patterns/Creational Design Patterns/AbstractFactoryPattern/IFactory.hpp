#pragma once
#include <iostream>
#include "Buttons.hpp"
#include "TextBox.hpp"
using namespace std;

class Ifactory{
    public:
        virtual IButton* createButton() = 0;
        virtual ITestBox* createTextBox() = 0;
};

class Windows : public Ifactory{
    public:
        IButton* createButton() override{
            return new winButton();
        }

        ITestBox* createTextBox(){
            return new winTextBox();
        }
};

class Mac : public Ifactory{
    public:
        IButton* createButton() override{
            return new macButton();
        }

        ITestBox* createTextBox(){
            return new macTextBox();
        }
};