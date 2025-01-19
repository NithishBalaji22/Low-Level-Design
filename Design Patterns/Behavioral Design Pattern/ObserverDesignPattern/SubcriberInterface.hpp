#pragma once
#include <iostream>
using namespace std;

class ISubcribers{
    public:
        virtual void notify(string msg) = 0;
};

