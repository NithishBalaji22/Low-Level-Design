#pragma once
#include <iostream>
#include "Receiver.hpp"
using namespace std;

class ICommand{
    public:
        virtual void execute() = 0;
        virtual void undo() = 0;
};

